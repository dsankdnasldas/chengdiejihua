#include "seetface.h"
#include "ui_seetface.h"
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QNetworkInterface>
#include <QHostAddress>

seetface::seetface(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_seetface)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/images/assets/yes.png"));
    ui->label->setScaledContents(true);
    ui->headpicLb->setPixmap(QPixmap(":/images/assets/crc.png"));
    ui->headpicLb->setScaledContents(true);
    startTimer(100);
    if (!cap.open(0, cv::CAP_DSHOW)) {
        qDebug() << "Failed to open camera.";
        return;
    }

    if (!cascade.load("D:/Codding/cdd/opencv/opencv46/etc/haarcascades/haarcascade_frontalface_alt2.xml")) {
        qDebug() << "Failed to load haarcascade_frontalface_alt2.xml.";
    }

    connect(&msocket,&QTcpSocket::disconnected,this, &seetface::start_connect);
    connect(&msocket,&QTcpSocket::connected,this, &seetface::stop_connect);
    connect(&msocket, &QTcpSocket::readyRead,this, &seetface::recv_data);
    connect(&mtimer, &QTimer::timeout,this,&seetface::timer_connect);
    mtimer.start(5000);

    m_flag =0;
    m_authstatus = PROGRESS;
    authent_disp(m_authstatus);
    //ui->widget_2->show();
}

seetface::~seetface()
{
    if (cap.isOpened()) {
        cap.release();
    }

    delete ui;
}

void seetface::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    //采集数据
    cv::Mat srcImage;
    cv::Mat grayImage;
    if(cap.grab())
    {
        cap.read(srcImage);//读取一帧数据
    }
    cv::resize(srcImage,srcImage,cv::Size(480,480));
    if (!cap.read(srcImage) || srcImage.empty()) {
        return;
    }
    cv::cvtColor(srcImage, grayImage, cv::COLOR_BGR2GRAY);
    std::vector<cv::Rect> faceRects;
    cascade.detectMultiScale(grayImage,faceRects);
    if (faceRects.size()>0 && m_flag>=0) {
        cv::Rect rect = faceRects.at(0);
        ui->headpicLb->move(rect.x,rect.y);
        if(m_flag > 2){
            std::vector<uchar> buf;
            cv::imencode(".jpg",srcImage,buf);
            QByteArray byte((const char*)buf.data(),buf.size());
            //准备发送
            quint64 backsize = byte.size();
            QByteArray sendData;
            QDataStream stream(&sendData,QIODevice::WriteOnly);
            stream.setVersion(QDataStream::Qt_5_14);
            stream<<backsize<<byte;
            //发送
            msocket.write(sendData);
            m_flag = -2;

            faceMat = srcImage(rect);
            //保存
            imwrite("./face.jpg",faceMat);
        }
        m_flag++;
    }
    if(faceRects.size() == 0)
    {
        //把人脸框移动到中心位置
        ui->headpicLb->move(100,60);
        m_authstatus=PROGRESS;
        authent_disp(m_authstatus);
        //ui->widget_2->hide();
        m_flag=0;
    }

    if(srcImage.data == nullptr) 
        return;

    cv::cvtColor(srcImage, srcImage, cv::COLOR_BGR2RGB);
    QImage image(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step, QImage::Format_RGB888);
    QPixmap mmp = QPixmap::fromImage(image.copy());
    ui->videoLb->setPixmap(mmp);
}

void seetface::timer_connect()
{
    quint16 port = 9999;

    QString localIp;
    const auto addrs = QNetworkInterface::allAddresses();
    for (const QHostAddress &addr : addrs) {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol && !addr.isLoopback()) {
            localIp = addr.toString();
            break;
        }
    }
    if (localIp.isEmpty()) {
        qDebug() << "No suitable IPv4 address found, falling back to localhost";
        localIp = QHostAddress(QHostAddress::LocalHost).toString();
    }
    QHostAddress hostAddress(localIp);
    msocket.connectToHost(hostAddress, port);
    qDebug() << "Connecting to server at" << hostAddress.toString() << ":" << port;
}

void seetface::stop_connect()
{
    mtimer.stop();
    qDebug()<<"Successfully connected to server";
}

void seetface::start_connect()
{
    mtimer.start(5000);//启动定时器
    qDebug()<<"Disconnected from server";
}

void seetface::recv_data()
{
    //{employeeID:%1,name:%2,department:软件,time:%3}
    QByteArray array = msocket.readAll();
    qDebug()<<array;
    //Json解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(array,&err);
    if(err.error != QJsonParseError::NoError)
    {
        qDebug()<<"json数据错误";
        return;
    }

    QJsonObject obj = doc.object();
    QString employeeID = obj.value("employeeID").toString();
    QString name = obj.value("name").toString();
    QString department = obj.value("department").toString();
    QString timestr = obj.value("time").toString();
    //查看解析的JSON数据中的关键字是否为空
    //如果是空，m_authstatus = FAIL
    //如果不为空，m_authstatus = SCUESS
    //ui->widget_2->show();
    if(employeeID != ""){
        m_authstatus = SUCCESS;
    }else{
        m_authstatus = FAIL;
        if(m_is_dis_face){
            //弹窗是否进行蓝牙辅助认证
            m_is_dis_face = false;
            QMessageBox msgBox(this);
            msgBox.setWindowTitle(tr("提示"));
            msgBox.setText(tr("是否开启蓝牙辅助认证？"));
            QPushButton *okBtn =
                msgBox.addButton(tr("确认"), QMessageBox::AcceptRole);

            QPushButton *cancelBtn =
                msgBox.addButton(tr("取消"), QMessageBox::RejectRole);

            msgBox.exec();
            
            if(msgBox.clickedButton() == okBtn)
            {
                // 跳转到蓝牙辅助认证界面
                BluetoothAssistWidget *bluetoothPage = new BluetoothAssistWidget();
                bluetoothPage->setAttribute(Qt::WA_DeleteOnClose);
                bluetoothPage->show();
                bluetoothPage->raise();
                bluetoothPage->activateWindow();
                // 如果当前页面需要关闭
                this->hide();
            }
            else
            {
                // 什么都不做，关闭弹窗
            }
        }
    }
    authent_disp(m_authstatus);
    ui->lineEdit->setText(employeeID);
    ui->lineEdit_2->setText(name);
    ui->lineEdit_3->setText(department);
    ui->lineEdit_4->setText(timestr);

    //通过样式来显示图片
    ui->headLb->setStyleSheet("border-radius:75px;border-image: url(./face.jpg);");
}


void seetface::authent_disp(int status)
{
    ui->label->clear();
    QString iconPath;
    QString statusText;
    if (status == PROGRESS) {
        iconPath = ":/images/assets/loading.gif";
        statusText = "认证中";
    } else if (status == SUCCESS) {
        iconPath = ":/images/assets/yes.png";
        statusText = "认证成功";
    } else if (status == FAIL) {
        iconPath = ":/images/assets/eorro.png";
        statusText = "认证失败";
    } else {
        iconPath = ":/images/assets/loading.gif";
        statusText = "认证中";
    }
    QPixmap icon(iconPath);
    ui->label->setPixmap(icon);
    ui->label->setScaledContents(true);
    ui->label->setFixedSize(icon.size());
    ui->label_2->setText(statusText);
    ui->widget_2->show();
    return;
}

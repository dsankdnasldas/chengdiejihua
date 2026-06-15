#include "seetface.h"
#include "ui_seetface.h"
#include <QDebug>
#include <QImage>
#include <QPainter>
#include <QPixmap>

seetface::seetface(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_seetface)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/images/assets/yes.png"));
    ui->label->setScaledContents(true);
    ui->headpicLb->setPixmap(QPixmap(":/images/assets/crc.png"));
    ui->headpicLb->setScaledContents(true);

    if (!cap.open(0, cv::CAP_DSHOW)) {
        qDebug() << "Failed to open camera.";
        return;
    }

    if (!cascade.load("D:/Codding/cdd/opencv/opencv46/etc/haarcascades/haarcascade_frontalface_alt2.xml")) {
        qDebug() << "Failed to load haarcascade_frontalface_alt2.xml.";
    }

    startTimer(100);
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

    if (!cap.isOpened()) {
        return;
    }

    cv::Mat srcImage;
    if (!cap.read(srcImage) || srcImage.empty()) {
        return;
    }

    cv::Mat grayImage;
    cv::cvtColor(srcImage, grayImage, cv::COLOR_BGR2GRAY);

    if (!cascade.empty()) {
        std::vector<cv::Rect> faceRects;
        cascade.detectMultiScale(grayImage, faceRects);
        if (!faceRects.empty()) {
            cv::Rect rect = faceRects.at(0);
            ui->headpicLb->move(rect.x, rect.y);
        } else {
            ui->headpicLb->move(100, 60);
        }
    }

    cv::cvtColor(srcImage, srcImage, cv::COLOR_BGR2RGB);
    QImage image(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step, QImage::Format_RGB888);
    QPixmap mmp = QPixmap::fromImage(image.copy());
    ui->videoLb->setPixmap(mmp);
}

#include "seetface.h"
#include "ui_seetface.h"
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QDebug>

seetface::seetface(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_seetface)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/images/assets/yes.png"));
    ui->label->setScaledContents(true);
    ui->headpicLb->setPixmap(QPixmap(":/images/assets/crc.png"));
    ui->headpicLb->setScaledContents(true);
}

seetface::~seetface()
{
    delete ui;
}

void seetface::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    cv::Mat srcImage;
    if (cap.grab()) {
        cap.read(srcImage);
    }

    if (srcImage.empty()) {
        return;
    }

    cv::Mat grayImage;
    cv::cvtColor(srcImage, grayImage, cv::COLOR_BGR2GRAY);

    std::vector<cv::Rect> faceRects;
    cascade.detectMultiScale(grayImage, faceRects);
    if (!faceRects.empty()) {
        cv::Rect rect = faceRects.at(0);
        ui->headpicLb->move(rect.x, rect.y);
    } else {
        ui->headpicLb->move(100, 60);
    }

    cv::cvtColor(srcImage, srcImage, cv::COLOR_BGR2RGB);
    QImage image(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step, QImage::Format_RGB888);
    QPixmap mmp = QPixmap::fromImage(image);
    ui->videoLb->setPixmap(mmp);
}

#pragma once

#include "ui_seetface.h"
#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <seeta/FaceDetector.h>
#include <QTcpSocket>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class seetface; }
QT_END_NAMESPACE

class seetface : public QMainWindow {
    Q_OBJECT

public:
    seetface(QWidget* parent = nullptr);
    ~seetface();
    void timerEvent(QTimerEvent *e) override;
    void recv_data();

private slots:
    void timer_connect();
    void stop_connect();
    void start_connect();

private:
    Ui_seetface* ui;
    cv::VideoCapture cap;
    cv::CascadeClassifier cascade;

    QTcpSocket msocket;
    QTimer mtimer;

    //标志是否是同一个人脸进入到识别区域
    int flag;

    //保存人类的数据
    cv::Mat faceMat;
};

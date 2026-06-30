#pragma once
#include "BluetoothAssistWidget.h"
#include "ui_seetface.h"
#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <seeta/FaceDetector.h>
#include <QTcpSocket>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QAbstractButton>
#include <QMessageBox>
#include <QPushButton>
enum authentication_status
{
    PROGRESS,
    SUCCESS,
    FAIL,
};

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
    void authent_disp(int state);

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
    int m_flag;
    //保存人类的数据
    cv::Mat faceMat;
    //返回的认证状态
    int m_authstatus;

    bool m_is_dis_face = true;
};

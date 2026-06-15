#pragma once

#include "ui_seetface.h"
#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <seeta/FaceDetector.h>

QT_BEGIN_NAMESPACE
namespace Ui { class seetface; }
QT_END_NAMESPACE

class seetface : public QMainWindow {
    Q_OBJECT

public:
    seetface(QWidget* parent = nullptr);
    ~seetface();
    void timerEvent(QTimerEvent *e) override;

private:
    Ui_seetface* ui;
    cv::VideoCapture cap;
    cv::CascadeClassifier cascade;
};

#include "seetface.h"

#include <QApplication>
#include <opencv2/opencv.hpp>
#include <seeta/FaceDetector.h>



#pragma comment(lib, "user32.lib")

using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    seetface w;
    w.show();
    return a.exec();
}
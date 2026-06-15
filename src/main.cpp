#include "seetface.h"
#include <QApplication>
#pragma comment(lib, "user32.lib")

using namespace cv;

int main(int argc, char *argv[])
{
    cv::setUseOptimized(false);
    QApplication a(argc, argv);
    seetface w;
    w.show();
    return a.exec();
}
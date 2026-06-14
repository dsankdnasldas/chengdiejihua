#include "seetface.h"
#include "ui_seetface.h"
#include <QImage>
#include <QPainter>
#include <QDebug>
seetface::seetface(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_seetface)
{
    ui->setupUi(this);
}

seetface::~seetface()
{
    delete ui;
}
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
    ui->label_4->setPixmap(QPixmap(":/images/assets/crc.png"));
    ui->label_4->setScaledContents(true);
}

seetface::~seetface()
{
    delete ui;
}

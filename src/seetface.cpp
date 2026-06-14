#include "seetface.h"

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
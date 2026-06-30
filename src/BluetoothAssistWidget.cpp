#include "BluetoothAssistWidget.h"
#include "ui_button.h"

BluetoothAssistWidget::BluetoothAssistWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BluetoothAssistWidget)
{
    ui->setupUi(this);
}

BluetoothAssistWidget::~BluetoothAssistWidget()
{
    delete ui;
}

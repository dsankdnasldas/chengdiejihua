#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class BluetoothAssistWidget; }
QT_END_NAMESPACE

class BluetoothAssistWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BluetoothAssistWidget(QWidget *parent = nullptr);
    ~BluetoothAssistWidget();

private:
    Ui::BluetoothAssistWidget *ui;
};

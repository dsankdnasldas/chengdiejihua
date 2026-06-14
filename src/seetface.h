#pragma once
#include "ui_seetface.h"
#include <QMainWindow>

class seetface : public QMainWindow {
    Q_OBJECT
    
public:
    seetface(QWidget* parent = nullptr);
    ~seetface();

private:
    Ui_seetface* ui;
};
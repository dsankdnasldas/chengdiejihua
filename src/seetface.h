#pragma once
#include "ui_seetface.h"
#include <QMainWindow>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class seetface; }
QT_END_NAMESPACE

class seetface : public QMainWindow {
    Q_OBJECT
    
public:
    seetface(QWidget* parent = nullptr);
    ~seetface();

private:
    Ui_seetface* ui;
};
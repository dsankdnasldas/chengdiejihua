/********************************************************************************
** Form generated from reading UI file 'seetface.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEETFACE_H
#define UI_SEETFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seetface
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *seetface)
    {
        if (seetface->objectName().isEmpty())
            seetface->setObjectName("seetface");
        seetface->resize(800, 600);
        centralwidget = new QWidget(seetface);
        centralwidget->setObjectName("centralwidget");
        seetface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(seetface);
        menubar->setObjectName("menubar");
        seetface->setMenuBar(menubar);
        statusbar = new QStatusBar(seetface);
        statusbar->setObjectName("statusbar");
        seetface->setStatusBar(statusbar);

        retranslateUi(seetface);

        QMetaObject::connectSlotsByName(seetface);
    } // setupUi

    void retranslateUi(QMainWindow *seetface)
    {
        seetface->setWindowTitle(QCoreApplication::translate("seetface", "seetface", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seetface: public Ui_seetface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEETFACE_H

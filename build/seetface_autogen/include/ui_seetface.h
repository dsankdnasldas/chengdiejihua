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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seetface
{
public:
    QWidget *centralwidget;
    QWidget *videoWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *headpicLb;
    QLabel *videoLb;
    QWidget *widget_3;
    QLabel *titleLb;
    QLabel *headLb;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_3;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_4;

    void setupUi(QMainWindow *seetface)
    {
        if (seetface->objectName().isEmpty())
            seetface->setObjectName("seetface");
        seetface->resize(800, 480);
        centralwidget = new QWidget(seetface);
        centralwidget->setObjectName("centralwidget");
        videoWidget = new QWidget(centralwidget);
        videoWidget->setObjectName("videoWidget");
        videoWidget->setGeometry(QRect(0, 0, 480, 480));
        videoWidget->setStyleSheet(QString::fromUtf8(""));
        widget_2 = new QWidget(videoWidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(90, 380, 271, 61));
        widget_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgba(49, 50, 54,69);"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setMinimumSize(QSize(31, 21));
        label->setMaximumSize(QSize(31, 21));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/assets/yes.png);"));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 25 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"border:none;\n"
"background-color: rgba(49, 50, 54,0);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        headpicLb = new QLabel(videoWidget);
        headpicLb->setObjectName("headpicLb");
        headpicLb->setGeometry(QRect(90, 50, 266, 266));
        headpicLb->setStyleSheet(QString::fromUtf8("border-image: url(:/images/assets/crc.png);"));
        videoLb = new QLabel(videoWidget);
        videoLb->setObjectName("videoLb");
        videoLb->setGeometry(QRect(0, 0, 480, 480));
        videoLb->raise();
        widget_2->raise();
        headpicLb->raise();
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(480, 0, 320, 480));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	\n"
"	background-color: rgb(37, 40, 49,0.9);\n"
"}\n"
"\n"
"QWidget#titleLb{\n"
"	\n"
"	font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QWidget#headLb{\n"
"	border-radius:75px;\n"
"}"));
        titleLb = new QLabel(widget_3);
        titleLb->setObjectName("titleLb");
        titleLb->setGeometry(QRect(0, 0, 320, 61));
        titleLb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        headLb = new QLabel(widget_3);
        headLb->setObjectName("headLb");
        headLb->setGeometry(QRect(80, 70, 150, 150));
        layoutWidget = new QWidget(widget_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 220, 301, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgb(37, 40, 49,0.9);\n"
"}\n"
"\n"
"QLabel{\n"
"	border:none;\n"
"	color: rgb(125, 100, 127);\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        lineEdit = new QLineEdit(widget_4);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(layoutWidget);
        widget_5->setObjectName("widget_5");
        widget_5->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgb(37, 40, 49,0.9);\n"
"}\n"
"\n"
"QLabel{\n"
"	border:none;\n"
"	color: rgb(125, 100, 127);\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_5);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lineEdit_2 = new QLineEdit(widget_5);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEdit_2);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(layoutWidget);
        widget_6->setObjectName("widget_6");
        widget_6->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgb(37, 40, 49,0.9);\n"
"}\n"
"\n"
"QLabel{\n"
"	border:none;\n"
"	color: rgb(125, 100, 127);\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget_6);
        label_8->setObjectName("label_8");

        horizontalLayout_5->addWidget(label_8);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        lineEdit_3 = new QLineEdit(widget_6);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_3);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(layoutWidget);
        widget_7->setObjectName("widget_7");
        widget_7->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgb(37, 40, 49,0.9);\n"
"}\n"
"\n"
"QLabel{\n"
"	border:none;\n"
"	color: rgb(125, 100, 127);\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget_7);
        label_9->setObjectName("label_9");

        horizontalLayout_6->addWidget(label_9);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        lineEdit_4 = new QLineEdit(widget_7);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_4);


        verticalLayout->addWidget(widget_7);

        seetface->setCentralWidget(centralwidget);

        retranslateUi(seetface);

        QMetaObject::connectSlotsByName(seetface);
    } // setupUi

    void retranslateUi(QMainWindow *seetface)
    {
        seetface->setWindowTitle(QCoreApplication::translate("seetface", "seetface", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("seetface", "\350\256\244\350\257\201\346\210\220\345\212\237", nullptr));
        headpicLb->setText(QString());
        videoLb->setText(QString());
        titleLb->setText(QCoreApplication::translate("seetface", "\344\272\272\350\204\270\350\257\206\345\210\253\350\200\203\345\213\244\347\263\273\347\273\237", nullptr));
        headLb->setText(QString());
        label_6->setText(QCoreApplication::translate("seetface", "\345\267\245\345\217\267", nullptr));
        lineEdit->setText(QCoreApplication::translate("seetface", "0001", nullptr));
        label_7->setText(QCoreApplication::translate("seetface", "\345\247\223\345\220\215", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("seetface", "0001", nullptr));
        label_8->setText(QCoreApplication::translate("seetface", "\351\203\250\351\227\250", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("seetface", "0001", nullptr));
        label_9->setText(QCoreApplication::translate("seetface", "\346\227\266\351\227\264", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("seetface", "0001", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seetface: public Ui_seetface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEETFACE_H

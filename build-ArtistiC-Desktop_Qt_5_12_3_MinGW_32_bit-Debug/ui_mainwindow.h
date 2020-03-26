/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *contenitoreEsterno;
    QVBoxLayout *contenitoreSX;
    QPushButton *pushButtonGrafico1;
    QSpacerItem *verticalSpacerSX;
    QLabel *LabelEtichetta_EMI_Artist;
    QListWidget *listWidget_EMI_Artist;
    QVBoxLayout *contenitoreDX;
    QPushButton *pushButton_grafico2;
    QSpacerItem *verticalSpacerDX;
    QLabel *LabelEtichetta2;
    QListWidget *listWidget_Universal_Artist;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        contenitoreEsterno = new QHBoxLayout();
        contenitoreEsterno->setObjectName(QString::fromUtf8("contenitoreEsterno"));
        contenitoreSX = new QVBoxLayout();
        contenitoreSX->setObjectName(QString::fromUtf8("contenitoreSX"));
        pushButtonGrafico1 = new QPushButton(centralwidget);
        pushButtonGrafico1->setObjectName(QString::fromUtf8("pushButtonGrafico1"));

        contenitoreSX->addWidget(pushButtonGrafico1);

        verticalSpacerSX = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Fixed);

        contenitoreSX->addItem(verticalSpacerSX);

        LabelEtichetta_EMI_Artist = new QLabel(centralwidget);
        LabelEtichetta_EMI_Artist->setObjectName(QString::fromUtf8("LabelEtichetta_EMI_Artist"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LabelEtichetta_EMI_Artist->sizePolicy().hasHeightForWidth());
        LabelEtichetta_EMI_Artist->setSizePolicy(sizePolicy);
        LabelEtichetta_EMI_Artist->setContextMenuPolicy(Qt::DefaultContextMenu);
        LabelEtichetta_EMI_Artist->setLayoutDirection(Qt::LeftToRight);
        LabelEtichetta_EMI_Artist->setAutoFillBackground(false);
        LabelEtichetta_EMI_Artist->setScaledContents(true);
        LabelEtichetta_EMI_Artist->setAlignment(Qt::AlignCenter);

        contenitoreSX->addWidget(LabelEtichetta_EMI_Artist);

        listWidget_EMI_Artist = new QListWidget(centralwidget);
        listWidget_EMI_Artist->setObjectName(QString::fromUtf8("listWidget_EMI_Artist"));

        contenitoreSX->addWidget(listWidget_EMI_Artist);


        contenitoreEsterno->addLayout(contenitoreSX);

        contenitoreDX = new QVBoxLayout();
        contenitoreDX->setObjectName(QString::fromUtf8("contenitoreDX"));
        pushButton_grafico2 = new QPushButton(centralwidget);
        pushButton_grafico2->setObjectName(QString::fromUtf8("pushButton_grafico2"));

        contenitoreDX->addWidget(pushButton_grafico2);

        verticalSpacerDX = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Fixed);

        contenitoreDX->addItem(verticalSpacerDX);

        LabelEtichetta2 = new QLabel(centralwidget);
        LabelEtichetta2->setObjectName(QString::fromUtf8("LabelEtichetta2"));
        LabelEtichetta2->setScaledContents(true);
        LabelEtichetta2->setAlignment(Qt::AlignCenter);

        contenitoreDX->addWidget(LabelEtichetta2);

        listWidget_Universal_Artist = new QListWidget(centralwidget);
        listWidget_Universal_Artist->setObjectName(QString::fromUtf8("listWidget_Universal_Artist"));

        contenitoreDX->addWidget(listWidget_Universal_Artist);


        contenitoreEsterno->addLayout(contenitoreDX);


        gridLayout->addLayout(contenitoreEsterno, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonGrafico1->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        LabelEtichetta_EMI_Artist->setText(QApplication::translate("MainWindow", "EMI Artist", nullptr));
        pushButton_grafico2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        LabelEtichetta2->setText(QApplication::translate("MainWindow", "Universal Artist", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'grafici.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICI_H
#define UI_GRAFICI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_grafici
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *grafici)
    {
        if (grafici->objectName().isEmpty())
            grafici->setObjectName(QString::fromUtf8("grafici"));
        grafici->resize(555, 420);
        buttonBox = new QDialogButtonBox(grafici);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(200, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(grafici);
        QObject::connect(buttonBox, SIGNAL(accepted()), grafici, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), grafici, SLOT(reject()));

        QMetaObject::connectSlotsByName(grafici);
    } // setupUi

    void retranslateUi(QDialog *grafici)
    {
        grafici->setWindowTitle(QApplication::translate("grafici", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class grafici: public Ui_grafici {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICI_H

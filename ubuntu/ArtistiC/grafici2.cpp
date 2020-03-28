#include "grafici2.h"
#include "ui_grafici2.h"

grafici2::grafici2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grafici2)
{
    ui->setupUi(this);


}

grafici2::~grafici2()
{
    delete ui;
}

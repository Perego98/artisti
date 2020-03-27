#include "grafici1.h"
#include "ui_grafici1.h"

grafici1::grafici1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grafici1)
{
    ui->setupUi(this);
}

grafici1::~grafici1()
{
    delete ui;
}

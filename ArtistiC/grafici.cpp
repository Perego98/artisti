#include "grafici.h"
#include "ui_grafici.h"

grafici::grafici(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grafici)
{
    ui->setupUi(this);
}

grafici::~grafici()
{
    delete ui;
}

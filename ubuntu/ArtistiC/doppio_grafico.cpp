#include "doppio_grafico.h"
#include "ui_doppio_grafico.h"

doppio_grafico::doppio_grafico(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::doppio_grafico)
{
    ui->setupUi(this);
}

doppio_grafico::~doppio_grafico()
{
    delete ui;
}

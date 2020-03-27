#ifndef DOPPIO_GRAFICO_H
#define DOPPIO_GRAFICO_H

#include <QMainWindow>

namespace Ui {
class doppio_grafico;
}

class doppio_grafico : public QMainWindow
{
    Q_OBJECT

public:
    explicit doppio_grafico(QWidget *parent = nullptr);
    ~doppio_grafico();

private:
    Ui::doppio_grafico *ui;
};

#endif // DOPPIO_GRAFICO_H

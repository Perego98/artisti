#ifndef GRAFICO1_H
#define GRAFICO1_H

#include <QMainWindow>
#include <QtCharts>

namespace Ui {
class grafico1;
}

class grafico1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit grafico1(QWidget *parent = nullptr);
    ~grafico1();


private:
    Ui::grafico1 *ui;
    QChartView * createch();
    void conta(QChar val);
    int count[27];// la prima cella è per tutti i caratteri che non sono lettere
};

#endif // GRAFICO1_H

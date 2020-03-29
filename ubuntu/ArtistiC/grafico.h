#ifndef GRAFICO_H
#define GRAFICO_H

#include <QMainWindow>
#include <QtCharts>

namespace Ui {
class grafico;
}

class grafico : public QMainWindow
{
    Q_OBJECT

public:
    explicit grafico(QWidget *parent = nullptr);
    ~grafico();


private:
    Ui::grafico *ui;
    QChartView * createch();
    void conta(QChar &val);
    int count[27];// la prima cella è per tutti i caratteri che non sono lettere

};

#endif // GRAFICO_H

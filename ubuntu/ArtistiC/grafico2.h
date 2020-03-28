#ifndef GRAFICO2_H
#define GRAFICO2_H

#include <QMainWindow>
#include <QtCharts>

namespace Ui {
class grafico2;
}

class grafico2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit grafico2(QWidget *parent = nullptr);
    ~grafico2();
    QChartView * createch();
    void conta(QChar val);

private:
    Ui::grafico2 *ui;
};

#endif // GRAFICO2_H

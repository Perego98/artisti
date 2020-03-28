#ifndef GRAFICI1_H
#define GRAFICI1_H

#include <QDialog>
#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>

namespace Ui {
class grafici1;
}

class grafici1 : public QDialog
{
    Q_OBJECT

public:
    explicit grafici1(QWidget *parent = nullptr);
    ~grafici1();

private:
    Ui::grafici1 *ui;
};

#endif // GRAFICI1_H

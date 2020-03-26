#ifndef GRAFICI_H
#define GRAFICI_H

#include <QDialog>

namespace Ui {
class grafici;
}

class grafici : public QDialog
{
    Q_OBJECT

public:
    explicit grafici(QWidget *parent = nullptr);
    ~grafici();

private:
    Ui::grafici *ui;
};

#endif // GRAFICI_H

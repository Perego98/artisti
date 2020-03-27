#ifndef GRAFICI2_H
#define GRAFICI2_H

#include <QDialog>

namespace Ui {
class grafici2;
}

class grafici2 : public QDialog
{
    Q_OBJECT

public:
    explicit grafici2(QWidget *parent = nullptr);
    ~grafici2();

private:
    Ui::grafici2 *ui;
};

#endif // GRAFICI2_H

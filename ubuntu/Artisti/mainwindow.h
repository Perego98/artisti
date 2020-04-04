#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QDir>
#include <QTextStream>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int count_emi[27];// la prima cella è per tutti i caratteri che non sono lettere
    int count_universal[27];// la prima cella è per tutti i caratteri che non sono lettere
    int emi;
    int universal;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_listWidget_Universal_Artist(const QString &path);
    void set_LabelEtichetta_EMI_Artist(const QString &path);

private:
    Ui::MainWindow *ui;
    QChartView * createch();
    void conta(QChar &val);
    void calcola_dati_emi();
    void calcola_dati_universal();
    void conta_universal(QChar &val);
    void conta_emi(QChar &val);
    QChartView * crea_emi();
    QChartView * crea_universal();
    QChartView * crea_numeri();

 public slots:
        void loadFileTXT();
};
#endif // MAINWINDOW_H

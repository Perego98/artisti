#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QListWidget>

#include "download.h"

// ELIMINARE
#include "downloadfiles.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
private:

    //download* manager;

    // ELIMINARE
     download * manager;
     download * manager2;

    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_listWidget_Universal_Artist(const QString &path);
    void set_LabelEtichetta_EMI_Artist(const QString &path);
private slots:
    void on_pushButtonGrafico1_clicked();
    void on_pushButton_grafico2_clicked();

    void on_pushButtonGrafico2_clicked();

private:
    Ui::MainWindow *ui;
    QListWidget *list1;

};
#endif // MAINWINDOW_H

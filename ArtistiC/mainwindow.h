#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_listWidget_Universal_Artist(const QString &path);
    void set_LabelEtichetta_EMI_Artist(const QString &path);
private:
    Ui::MainWindow *ui;
    QListWidget *list1;

};
#endif // MAINWINDOW_H

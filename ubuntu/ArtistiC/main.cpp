#include "mainwindow.h"
#include "download.h"
#include "splitfile.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //File Name
    QString et1 = "List_of_EMI_artists.txt";
    QString et2 = "List_of_Universal_artists.txt";


    w.set_listWidget_Universal_Artist(et1);
    w.set_LabelEtichetta_EMI_Artist(et2);

    w.show();
    return a.exec();
}

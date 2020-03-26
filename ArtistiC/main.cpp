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


    //url
    QUrl etichetta1("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt");
    QUrl etichetta2("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt");

    // download file
    download manager;

    manager.startDownload(etichetta1);
    manager.startDownload(etichetta2);

    w.set_listWidget_Universal_Artist(et1);
    w.set_LabelEtichetta_EMI_Artist(et2);




    w.show();
    return a.exec();
}

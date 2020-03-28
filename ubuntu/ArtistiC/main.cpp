#include "mainwindow.h"
#include "download.h"
#include "splitfile.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //File Name
   QString et2 = "List_of_EMI_artists.txt";
    QString et1 = "List_of_Universal_artists.txt";

/*     //url
    QString etichetta1("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt");
    QString etichetta2("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt");

    download * manager;
    try {
        manager = new download();
        manager->setTarget(etichetta1);
        manager->setFileName(et1);
        manager->downloadstr();
    } catch (...) {
        delete manager;
        manager = nullptr;
    }

    download * manager2;
    try {
        manager2 = new download(et2);
        manager2->setTarget(etichetta2);
        //manager2->setFileName(et2);
        manager2->downloadstr();
    } catch (...) {
        delete manager2;
        manager2 = nullptr;
    }

*/

    MainWindow w;


    w.set_listWidget_Universal_Artist(et2);
    w.set_LabelEtichetta_EMI_Artist(et1);

    w.show();
    return a.exec();

}

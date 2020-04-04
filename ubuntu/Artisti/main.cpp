#include "mainwindow.h"
#include "downloadfiles.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

   // creo un oggetto downloadfiles che
   // si collegherà  e scaricherà i file
   downloadfiles managerD;

   // collego il segnale done, lanciato alla fine dei download
   // con il metodo loadFileTXT della mainWindow,
   // cosi caricherò il file di testo solo una volta che sono sicuro sia stato scaricato
   QObject::connect(&managerD, SIGNAL(done()), &w, SLOT(loadFileTXT()), Qt::QueuedConnection);

   // faccio partirte il download
   QTimer::singleShot(0, &managerD, SLOT(download()));

    w.show();
    return a.exec();
}

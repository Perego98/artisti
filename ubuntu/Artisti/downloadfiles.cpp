#include "downloadfiles.h"
#include <QCoreApplication>
#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <iostream>

downloadfiles::downloadfiles(){
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
                SLOT(downloadFinished(QNetworkReply*)));
}

void downloadfiles::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

#if QT_CONFIG(ssl)
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            SLOT(sslErrors(QList<QSslError>)));
#endif

    currentDownloads.append(reply);
}


// trova il nome del file dall'indirizzo url
// se esiste di gia lo elimino
QString downloadfiles::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download.txt";

    // se il file esiste di già lo elimino
    // nel caso il nuovo file sia una versione aggiornata
    if (QFile::exists(basename)) {
        QFile::remove(basename);
    }

    return basename;
}

// salva il file
bool downloadfiles::saveFile(const QString &filename, QIODevice *data)
{
    QFile file(filename);

    // se non riesco ad aprire il file in sola scrittura
    // stampo messaggio di errore e ritorno false
    if (!file.open(QIODevice::WriteOnly)) {
        std::cout << "Non riesco ad aprire" << qPrintable(filename)
                  << "per la scrittura:" << qPrintable(file.errorString()) << std::endl;
        return false;
    }

    // scrivo su file
    file.write(data->readAll());

    // una volta finito chiudo il file
    file.close();

    return true;
}

bool downloadfiles::isHttpRedirect(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return statusCode == 301 || statusCode == 302 || statusCode == 303
           || statusCode == 305 || statusCode == 307 || statusCode == 308;
}

void downloadfiles::download()
{
    QUrl etichetta1("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_Universal_artists.txt");
    QUrl etichetta2("http://www.ivl.disco.unimib.it/minisites/cpp/List_of_EMI_artists.txt");

    // faccio partire i download dei due file, prima uno e una volta finito parte il secondo
    doDownload(etichetta1);
    doDownload(etichetta2);

}


void downloadfiles::sslErrors(const QList<QSslError> &sslErrors)
{
#if QT_CONFIG(ssl)
    for (const QSslError &error : sslErrors)
        std::cout << "Errore SSL: " << qPrintable(error.errorString()) << std::endl;
#else
    Q_UNUSED(sslErrors);
#endif
}


void downloadfiles::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error()) {
        std::cout << "Download di " << url.toEncoded().constData()
                  << " fallito: " << qPrintable(reply->errorString()) << std::endl;

    } else {
        if (isHttpRedirect(reply)) {
            std::cout << "Richiesta reindirizzata" << std::endl;
        } else {
            QString filename = saveFileName(url);
            if (saveFile(filename, reply)) {
                std::cout << "Il download di " << url.toEncoded().constData()
                          << " e' stato effettuato, salvato in " << qPrintable(filename) << std::endl;
            }
        }
    }

    currentDownloads.removeAll(reply);
    reply->deleteLater();

    if (currentDownloads.isEmpty()) {
        // quando tutti i download sono finiti emetto il segnale done()
        // che servirà per poter lanciare altri comandi una volta
        //che il download dei file sarà finito
        emit done();
    }
}

downloadfiles::~downloadfiles() {

}


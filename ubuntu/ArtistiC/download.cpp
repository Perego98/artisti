#include "download.h"
#include <QDir>
download::download() :  QObject(0), reply(nullptr) {
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
}

download::download(const QString& file_name) :  QObject(0), reply(nullptr) {
    this->file_name = file_name;
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
}

download::~download() {
    delete reply;
    reply = nullptr;
}


void download::setTarget(const QUrl &t) {
    this->target = t;
}

void download::downloadFinished(QNetworkReply *data) {
    QFile localFile(file_name);
    if (!localFile.open(QIODevice::WriteOnly))
        return;
    const QByteArray sdata = data->readAll();
    localFile.write(sdata);
    //qDebug() << sdata;
    localFile.close();

    emit done();
}

void download::downloadstr() {
    QNetworkRequest request(target);
    QObject::connect(manager.get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));

}

void download::setFileName(const QString& fn){
    file_name = fn;
}

void download::downloadProgress(qint64 recieved, qint64 total) {
    //qDebug() << recieved << total;
}

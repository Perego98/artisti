#include "downloadfiles.h"

#include <QFile>

downloadfiles::downloadfiles(QString &file_name) :  QObject(0), reply(nullptr) {
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*, file_name)));
}


downloadfiles::~downloadfiles() {

}


void downloadfiles::downloadFinished(QNetworkReply *data, QString &file_name) {
    QFile localFile(file_name);
    if (!localFile.open(QIODevice::WriteOnly))
        return;
    const QByteArray sdata = data->readAll();
    localFile.write(sdata);
    qDebug() << sdata;
    localFile.close();
}

void downloadfiles::download(const QString &_url) {
    QUrl url = QUrl::fromEncoded(_url.toLocal8Bit());
    QNetworkRequest request(url);
    QObject::connect(manager.get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));

}

void downloadfiles::downloadProgress(qint64 recieved, qint64 total) {
    qDebug() << recieved << total;
}

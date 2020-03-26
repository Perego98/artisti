#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>


#include <stdio.h>

class download : public QObject{

    Q_OBJECT
    QNetworkAccessManager NetworkManager;
    QList<QNetworkReply *> currDownload;

public:
    download();
    void startDownload(const QUrl &url);
    QString createFileName(const QUrl &url);
    bool saveFile(const QString &filename, QIODevice *data);

public slots:
    void downloadFinish(QNetworkReply *reply);

};

#endif // DOWNLOAD_H

#ifndef DOWNLOAD_H
#define DOWNLOAD_H


#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

//#include <QFile>
//#include <QFileInfo>
//#include <QList>
//#include <QStringList>
//#include <QTimer>
//#include <QNetworkRequest>

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

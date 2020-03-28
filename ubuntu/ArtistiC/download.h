#ifndef DOWNLOAD_H
#define DOWNLOAD_H


//#include <QNetworkAccessManager>
//#include <QNetworkReply>
//#include <QUrl>
//#include <QFile>
//#include <QDebug>

//#include <QFile>
//#include <QFileInfo>
//#include <QList>
//#include <QStringList>
//#include <QTimer>
//#include <QNetworkRequest>

#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QNetworkReply>
#include <QLabel>
#include <QCoreApplication>
#include <QUrl>
#include <QFile>
#include <QDebug>

#include <stdio.h>

class download : public QObject{

    Q_OBJECT

private:
    QNetworkAccessManager manager;
    QNetworkReply* reply;
    QString file_name;
    QUrl target;

     void connectSignalsAndSlots();


public:
    explicit download();
     download(const QString&);
    ~download();

    void setTarget(const QUrl& t);
    void setFileName(const QString& fn);


signals:
    void done();

public slots:
    void downloadstr();
    void downloadFinished(QNetworkReply* data);
    void downloadProgress(qint64 recieved, qint64 total);

};

#endif // DOWNLOAD_H

#ifndef DOWNLOADFILES_H
#define DOWNLOADFILES_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

class downloadfiles : public QObject
{
private:
    Q_OBJECT
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currDownload;
    QNetworkReply *reply;


public:
    downloadfiles(QString &file_name);
    ~downloadfiles();
    void downloadFinished(QNetworkReply *data,  QString &file_name);
    void download(const QString &_url);
    void downloadProgress(qint64 recieved, qint64 total);
};

#endif // DOWNLOADFILES_H

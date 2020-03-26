#include "download.h"

#include <QDir>

download::download()
{
    connect(&NetworkManager, SIGNAL(finished(QNetworkReply*)),
            SLOT(downloadFinish(QNetworkReply*)));
}

void download::startDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = NetworkManager.get(request);

    currDownload.append(reply);
}

QString download::createFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "et1";

    QString downloadDirectory = QDir::currentPath();
    //QString downloadDirectory = QDir::cleanPath(directory->text().trimmed());
    basename.prepend(downloadDirectory + '/');

    if (QFile::exists(basename)) {
        // already exists, don't overwrite
       QFile::remove(basename);
    }


    return basename;
}

bool download::saveFile(const QString &filename, QIODevice *data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Could not open %s for writing: %s\n",
                qPrintable(filename),
                qPrintable(file.errorString()));
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}


void download::downloadFinish(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        QString filename = createFileName(url);
        if (saveFile(filename, reply))
            printf("Download of %s succeded (saved to %s)\n",
                   url.toEncoded().constData(), qPrintable(filename));
    }

    currDownload.removeAll(reply);
    reply->deleteLater();
}



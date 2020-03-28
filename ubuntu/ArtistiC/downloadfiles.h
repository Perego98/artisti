#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>


class downloadfiles : public QObject {
    Q_OBJECT
public:
    explicit downloadfiles();
    ~downloadfiles();

    void setTarget(const QString& t);

private:
    QNetworkAccessManager manager;
    QString target;

signals:
    void done();

public slots:
    void download();
    void downloadFinished(QNetworkReply* data);
    void downloadProgress(qint64 recieved, qint64 total);
};

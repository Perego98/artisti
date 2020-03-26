#ifndef SPLITFILE_H
#define SPLITFILE_H

#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <vector>

class splitFile
{
private:
    const QString _path;
public:
    splitFile(const QString &path);

    std::vector<QLabel> process_line();


};

#endif // SPLITFILE_H

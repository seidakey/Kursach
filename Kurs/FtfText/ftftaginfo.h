#ifndef FTFTAGINFO_H
#define FTFTAGINFO_H

#include "ftftag.h"
#include <QVector>
#include <QString>

class FtfTagInfo
{
private:
    static QVector<QString> name_v;
public:
    FtfTagInfo() = delete;
    static void init();
    static const QString &getTagName(FtfTag tag);
};

#endif // FTFTAGINFO_H

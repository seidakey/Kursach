#ifndef XFTFTAGSMAPPER_H
#define XFTFTAGSMAPPER_H

#include "FtfText/ftftag.h"
#include <QString>
#include <QMap>

class XFtfTagsMapper
{
    static QMap<QString, FtfTag> map_;
public:
    XFtfTagsMapper() = delete;
    static void init();
    static FtfTag get(const QString &tagName);
};

#endif // FTFTAGSMAPPER_H

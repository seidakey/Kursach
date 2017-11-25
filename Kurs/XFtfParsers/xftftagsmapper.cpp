#include "xftftagsmapper.h"
#include "xftftagname.h"

QMap<QString, FtfTag> XFtfTagsMapper::map_;

void XFtfTagsMapper::init()
{
    map_.insert(XFtfTagName::text, TEXT);
    map_.insert(XFtfTagName::paragraph, PARAGRAPH);
    map_.insert(XFtfTagName::question, QUESTION);
}

FtfTag XFtfTagsMapper::get(const QString &tagName) {
    return map_[tagName];
}

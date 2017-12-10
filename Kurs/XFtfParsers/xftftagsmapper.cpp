#include "xftftagsmapper.h"
#include "xftftagname.h"

QMap<QString, FtfTag> XFtfTagsMapper::map_;

void XFtfTagsMapper::init()
{
    map_.insert(XFtfTagName::TEXT, TEXT);
    map_.insert(XFtfTagName::PARAGRAPH, PARAGRAPH);
    map_.insert(XFtfTagName::QUESTION, QUESTION);
}

FtfTag XFtfTagsMapper::get(const QString &tagName) {
    return map_[tagName];
}

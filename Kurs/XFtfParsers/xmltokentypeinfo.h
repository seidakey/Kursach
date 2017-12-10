#ifndef XMLTOKENTYPEINFO_H
#define XMLTOKENTYPEINFO_H

#include <QString>
#include <QXmlStreamReader>

class XmlTokenTypeInfo
{
    static QVector<QString> name_v;
public:
    XmlTokenTypeInfo() = delete;
    static void init();
    static const QString &getName(QXmlStreamReader::TokenType tokenType);
};

#endif // XMLTOKENTYPEINFO_H

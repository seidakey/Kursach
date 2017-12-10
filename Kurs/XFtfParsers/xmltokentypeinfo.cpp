#include "xmltokentypeinfo.h"

QVector<QString> XmlTokenTypeInfo::name_v;

void XmlTokenTypeInfo::init()
{
    name_v.resize(11);
    name_v[QXmlStreamReader::NoToken] = "NoToken";
    name_v[QXmlStreamReader::Invalid] = "Invalid";
    name_v[QXmlStreamReader::StartDocument] = "StartDocument";
    name_v[QXmlStreamReader::EndDocument] = "EndDocument";
    name_v[QXmlStreamReader::StartElement] = "StartElement";
    name_v[QXmlStreamReader::EndElement] = "EndElement";
    name_v[QXmlStreamReader::Characters] = "Characters";
    name_v[QXmlStreamReader::Comment] = "Comment";
    name_v[QXmlStreamReader::DTD] = "DTD";
    name_v[QXmlStreamReader::EntityReference] = "EntityReference";
    name_v[QXmlStreamReader::ProcessingInstruction] = "ProcessingInstruction";
}

const QString &XmlTokenTypeInfo::getName(QXmlStreamReader::TokenType tokenType)
{
    return name_v[tokenType];
}


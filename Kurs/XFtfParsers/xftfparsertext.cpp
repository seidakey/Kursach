#include "xftfparsertext.h"
#include "xftftagname.h"
#include <QDebug>
#include <QXmlStreamAttribute>
#include <QXmlStreamAttributes>
#include <QLoggingCategory>

bool XFtfParserText::readDocument(QXmlStreamReader *xml) {
    xml->readNext();
    if(xml->tokenType() != QXmlStreamReader::StartDocument)
    {
        qCritical() << "XftfParserText:readDocument: tokenType != StartDocument."
                       " tokenType = " + xml->tokenString() + " != StartDocument";
        return false;
    }
    xml->readNext();
    if(xml->tokenType() != QXmlStreamReader::StartElement)
    {
        qCritical() << "XftfParserText:readDocument: "
                       "tokenType = " + xml->tokenString() + " != StartElement";
        return false;
    }
    else if(xml->name() != XFtfTagName::text)
    {
        qCritical() << "XftfParserText:readDocument: "
                       "node name != '" + XFtfTagName::text + "'";
        return false;
    }
    readText(xml);
}

bool XFtfParserText::readText(QXmlStreamReader *xml)
{
    for(xml->readNext(); xml->tokenType() != QXmlStreamReader::EndElement; xml->readNext()) {
        if(xml->tokenType() == QXmlStreamReader::StartElement) {
            if(xml->name() == XFtfTagName::paragraph)
                readParagraph(xml);
            else if (xml->name() == XFtfTagName::question)
                readQuestion(xml);
        }
    }
    if(xml->name() == XFtfTagName::text) {
        qDebug() << xml->name() << "well";
    }
    else
    {
        qDebug() << xml->name() << "bad";
    }
}

bool XFtfParserText::readParagraph(QXmlStreamReader *xml)
{
    xml->readNext();
    if(xml->tokenType() == QXmlStreamReader::Characters) {
        qDebug() << xml->text() << "well";
    }
    xml->readNext();
    if(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == XFtfTagName::paragraph) {
        qDebug() << xml->name() << "well";
    }
}

bool XFtfParserText::readQuestion(QXmlStreamReader *xml)
{
    QXmlStreamAttributes attrs= xml->attributes();
    QXmlStreamAttribute attr = attrs.at(0);
    if(attr.name() == "tag") {
        qDebug() << "tag" << attr.value();
    }
    xml->readNext();
    if(xml->tokenType() == QXmlStreamReader::Characters) {
        qDebug() << xml->text() << "well";
    }
    xml->readNext();
    if(xml->tokenType() == QXmlStreamReader::EndElement && xml->name() == XFtfTagName::question) {
        qDebug() << xml->name() << "well";
    }
}

#include "documentdata.h"
#include "XFtfParsers/xftfparsertext.h"
#include <QXmlStreamReader>

FtfDocument *DocumentData::document = new FtfDocument;

void DocumentData::load(QIODevice *device)
{
    QXmlStreamReader xml;
    xml.setDevice(device);
    FtfDocument *doc = new FtfDocument;
    XFtfParserText ftfParser(doc, &xml);
    if(ftfParser.readDocument())
    {
        delete document;
        document = doc;
    }
    else
        delete doc;
}

FtfDocument *DocumentData::getDocument()
{
    return document;
}

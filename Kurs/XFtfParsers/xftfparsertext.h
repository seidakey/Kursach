#ifndef XFTFPARSERTEXT_H
#define XFTFPARSERTEXT_H

#include <QXmlStreamReader>
#include <functional>

class XFtfParserText
{
private:
    static bool readParagraph(QXmlStreamReader *xml);
    static bool readQuestion(QXmlStreamReader *xml);
    static bool readText(QXmlStreamReader *xml);
public:
    XFtfParserText() = delete;
    static void init();
    static bool readDocument(QXmlStreamReader *xml);
};

#endif // XFTFPARSERTEXT_H

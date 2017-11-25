#ifndef XFTFREADER_H
#define XFTFREADER_H

#include <QXmlStreamReader>

class XftfReader
{
protected:
    QXmlStreamReader xml;

public:
    XftfReader();
    bool read(QIODevice *device);
    bool readParagraph();
};

#endif // XFTFREADER_H

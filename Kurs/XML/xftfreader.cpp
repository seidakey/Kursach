#include "xftfreader.h"
#include <QDebug>

XftfReader::XftfReader()
{
}

bool XftfReader::read(QIODevice *device)
{
    xml.setDevice(device);
    if (xml.readNextStartElement()) {
        if (xml.name() == "text"){
            while(xml.readNext()){
                QString s = xml.readElementText();
                qDebug(qPrintable(s));
            }
        }
        else
            xml.raiseError(QObject::tr("Incorrect file"));
    }
    /*
    while(!xml.atEnd() && !xml.hasError()) {
        xml.readNextStartElement();
        qDebug() << xml.name() << xml.readElementText();
    }
    if(xml.hasError())
        qDebug() << xml.errorString();
    return false;
    qDebug() << xml.name() << xml.readElementText();
    qDebug() << xml.readNextStartElement();
    qDebug() << xml.name() << xml.readElementText();
    qDebug() << xml.readNext();
    qDebug() << xml.name() << xml.readElementText();
    qDebug() << xml.readNext();
    qDebug() << xml.name() << xml.readElementText();
    */
    return true;
}

bool XftfReader::readParagraph() {
}

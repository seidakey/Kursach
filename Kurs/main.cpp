#include "mainwindow.h"
#include "XML/xftfreader.h"
#include "XFtfParsers/xftfparsertext.h"
#include <QXmlStreamReader>
#include <QApplication>
#include <QtWebEngineWidgets>
#include <QLoggingCategory>
#include "Logging/logger.h"

void init() {
    Logger::init();
}

int main(int argc, char *argv[])
{
    init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile file;
    file.setFileName("/home/misha/Programs/Kursach/Kurs/testXML.xml");
    file.open(QIODevice::ReadOnly | QIODevice::Text );
    QXmlStreamReader xml;
    xml.setDevice(&file);
    XFtfParserText::readDocument(&xml);

    return a.exec();
}

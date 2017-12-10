#include "mainwindow.h"
#include "XML/xftfreader.h"
#include "XFtfParsers/xftfparsertext.h"
#include <QXmlStreamReader>
#include <QApplication>
#include <QtWebEngineWidgets>
#include <QLoggingCategory>
#include "Logging/logger.h"
#include "FtfText/Elements/paragraph.h"
#include "FtfText/Elements/text.h"
#include  "FtfText/ftftaginfo.h"
#include "FtfText/ftfdocument.h"
#include "XFtfParsers/xmltokentypeinfo.h"

void init()
{
    Logger::init();
    FtfTagInfo::init();
    XmlTokenTypeInfo::init();
}

QString test()
{
    QFile file;
    file.setFileName("/home/misha/Programs/Kursach/Kurs/testXML.xml");
    file.open(QIODevice::ReadOnly | QIODevice::Text );
    QXmlStreamReader xml;
    xml.setDevice(&file);
    FtfDocument doc;
    XFtfParserText ftfParser(&doc, &xml);
    qDebug() << ftfParser.readDocument();
    FtfElement<TEXT> text;
    FtfElement<PARAGRAPH> par;
    qDebug() << text.getTag() << par.getTag();
    QString html;
    QMap<QString, Question> &qs = doc.getQuestions()->getQuestions();
    for(Question q : qs.values())
    {
        static const QString htmlNextLine("<br/>");
        html = html % q.getText() % htmlNextLine;
        for(QSharedPointer<FtfAbstractElement> elem : q.getAnswers())
        {
            html = html % elem->getHtml() % htmlNextLine;
        }
        html = html % htmlNextLine;
    }
    return html;
}

int main(int argc, char *argv[])
{
    init();
    QApplication a(argc, argv);
    QString html = test();

    MainWindow w(html);
    w.show();
    return a.exec();
}

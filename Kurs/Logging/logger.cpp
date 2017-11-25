#include "logger.h"
#include <QTextStream>
#include <QDateTime>
#include <iostream>

QFile Logger::file_;

void Logger::init()
{
    file_.setFileName("/home/misha/Programs/Kursach/Kurs/log.log");
    file_.open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);
}

void Logger::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    Q_UNUSED(context)
    // Open stream file writes
    QTextStream out(&file_);
    // Write the date of recording
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    // By type determine to what level belongs message
    if(type == QtDebugMsg) {
        printf("%s\n", msg.toLatin1().data());
        fflush(stdout);
        return;
    }
    switch (type)
    {
    case QtInfoMsg:     out << "INF "; break;
    case QtWarningMsg:  out << "WRN "; break;
    case QtCriticalMsg: out << "CRT "; break;
    case QtFatalMsg:    out << "FTL "; break;
    }
    // Write to the output category of the message and the message itself
    out << msg << endl;
    out.flush();    // Clear the buffered data
}

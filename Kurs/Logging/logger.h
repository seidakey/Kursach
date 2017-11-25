#ifndef LOGGER_H
#define LOGGER_H

#include <QLoggingCategory>
#include <QFile>

class Logger
{
    static QFile file_;
    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
public:
    Logger() = delete;
    static void init();
};

#endif // LOGGER_H

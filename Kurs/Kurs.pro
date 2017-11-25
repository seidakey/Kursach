#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T15:20:31
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kurs
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Widgets/widgetchooserlist.cpp \
    Widgets/widgetchooseritem.cpp \
    XFtfParsers/xftfparsertext.cpp \
    Logging/logger.cpp \
    XFtfParsers/xftftagsmapper.cpp

HEADERS  += mainwindow.h \
    Widgets/widgetchooserlist.h \
    Widgets/widgetchooseritem.h \
    XFtfParsers/xftfparsertext.h \
    Logging/logger.h \
    XFtfParsers/xftftagsmapper.h \
    XFtfParsers/xftftagname.h \
    FtfText/ftftag.h

FORMS    += mainwindow.ui

DISTFILES += \
    test.html \
    testXML.xml \
    log.log

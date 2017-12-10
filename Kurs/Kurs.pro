#-------------------------------------------------
#
# Project created by QtCreator 2017-11-19T15:20:31
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kurs
TEMPLATE = app

CONFIG += C++14

SOURCES += main.cpp\
        mainwindow.cpp \
    Widgets/widgetchooserlist.cpp \
    Widgets/widgetchooseritem.cpp \
    XFtfParsers/xftfparsertext.cpp \
    Logging/logger.cpp \
    XFtfParsers/xftftagsmapper.cpp \
    FtfText/ftftaginfo.cpp \
    FtfText/AbstractElement/ftfabstractelement.cpp \
    FtfText/ftfdocument.cpp \
    XFtfParsers/xmltokentypeinfo.cpp \
    XFtfParsers/xftfparserdocument.cpp \
    FtfText/Questions/question.cpp \
    FtfText/Questions/questions.cpp \
    Widgets/Modes/tutormodewidget.cpp \
    Dao/documentdao.cpp \
    Data/documentdata.cpp

HEADERS  += mainwindow.h \
    Widgets/widgetchooserlist.h \
    Widgets/widgetchooseritem.h \
    XFtfParsers/xftfparsertext.h \
    Logging/logger.h \
    XFtfParsers/xftftagsmapper.h \
    XFtfParsers/xftftagname.h \
    FtfText/ftftag.h \
    FtfText/ftftaginfo.h \
    FtfText/AbstractElement/ftfelementsmodule.h \
    FtfText/AbstractElement/ftfattributesmodule.h \
    FtfText/AbstractElement/ftftextmodule.h \
    FtfText/AbstractElement/ftfmediumelement.h \
    FtfText/AbstractElement/ftfabstractelement.h \
    FtfText/AbstractElement/ftfelement.h \
    FtfText/Elements/text.h \
    FtfText/Elements/paragraph.h \
    FtfText/Elements/elements.h \
    FtfText/Elements/title.h \
    FtfText/Elements/sentence.h \
    FtfText/Elements/questionpointer.h \
    FtfText/ftfdocument.h \
    XFtfParsers/xmltokentypeinfo.h \
    XFtfParsers/xftfparserdocument.h \
    FtfText/Questions/question.h \
    FtfText/Questions/questions.h \
    Widgets/Modes/tutormodewidget.h \
    Dao/documentdao.h \
    Data/documentdata.h

FORMS    += mainwindow.ui

DISTFILES += \
    test.html \
    testXML.xml \
    log.log

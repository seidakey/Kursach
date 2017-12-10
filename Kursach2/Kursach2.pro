#-------------------------------------------------
#
# Project created by QtCreator 2017-12-08T19:50:58
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kursach2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    Model/question.cpp \
    View/textbrowser.cpp \
    View/simpleanswerbrowser.cpp \
    View/hintsbrowser.cpp \
    Data/questions.cpp \
    Model/workbook.cpp \
    DAO/workbookdao.cpp \
    Databases/databasemodel.cpp \
    Databases/database.cpp \
    View/conspectuschooser.cpp \
    Model/workbookinfo.cpp \
    DAO/workbookinfodao.cpp \
    View/mainwidget.cpp \
    Widgets/listmenulayout.cpp \
    View/conspectusview.cpp \
    View/repetitorview.cpp \
    View/simplehintsandanswerbrowser.cpp \
    View/repetitorquestionbrowser.cpp \
    Widgets/alignlayout.cpp \
    Widgets/alignwidget.cpp

HEADERS  += mainwindow.h \
    Model/question.h \
    View/textbrowser.h \
    View/simpleanswerbrowser.h \
    View/hintsbrowser.h \
    Data/questions.h \
    Model/workbook.h \
    DAO/workbookdao.h \
    Databases/databasemodel.h \
    Databases/database.h \
    View/conspectuschooser.h \
    Model/workbookinfo.h \
    DAO/workbookinfodao.h \
    View/mainwidget.h \
    Widgets/listmenulayout.h \
    View/conspectusview.h \
    View/repetitorview.h \
    View/simplehintsandanswerbrowser.h \
    View/repetitorquestionbrowser.h \
    Widgets/alignlayout.h \
    Widgets/alignwidget.h

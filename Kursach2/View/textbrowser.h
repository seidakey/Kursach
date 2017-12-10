#ifndef TEXTBROWSER_H
#define TEXTBROWSER_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QTextBrowser>
#include <QLineEdit>
#include "Model/question.h"

class TextBrowser : public QWidget
{
protected:
    QListWidget *listWidget = new QListWidget;
    QTextBrowser *textBrowser = new QTextBrowser;
    QPushButton *btn_add_hint = new QPushButton;
    QLineEdit *lineEdit = new QLineEdit;
public:
    TextBrowser();
    void setQuestion(Question *question);
};

#endif // TEXTBROWSER_H

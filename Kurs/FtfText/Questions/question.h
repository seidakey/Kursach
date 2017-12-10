#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QSharedPointer>
#include <QList>
#include "FtfText/AbstractElement/ftfabstractelement.h"

class Question
{
protected:
    QString text;
    QList<QSharedPointer<FtfAbstractElement>> answer_l;
    int complexity;
public:
    int getComplexity();
    void setComplexity(int complexity);
    const QString &getText();
    void setText(const QString &text);
    QList<QSharedPointer<FtfAbstractElement>> &getAnswers();
    void addAnswer(QSharedPointer<FtfAbstractElement> answer);
};

#endif // QUESTION_H

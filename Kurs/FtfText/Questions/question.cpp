#include "question.h"

int Question::getComplexity()
{
    return complexity;
}

void Question::setComplexity(int complexity)
{
    this->complexity = complexity;
}

const QString &Question::getText()
{
    return text;
}

void Question::setText(const QString &text)
{
    this->text = text;
}

QList<QSharedPointer<FtfAbstractElement>> &Question::getAnswers()
{
    return answer_l;
}

void Question::addAnswer(QSharedPointer<FtfAbstractElement> answer)
{
    answer_l.append(answer);
}


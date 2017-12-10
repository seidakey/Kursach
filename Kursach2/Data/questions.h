#ifndef QUESTIONS_H
#define QUESTIONS_H

#include "Model/question.h"
#include <QVector>

class Questions
{
private:
    static QVector<Question> questions;
public:
    Questions() = delete;
    static void init();
};

#endif // QUESTIONS_H

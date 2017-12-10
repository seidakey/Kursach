#ifndef FTFDOCUMENT_H
#define FTFDOCUMENT_H

#include "Elements/elements.h"
#include "FtfText/Questions/questions.h"
#include <QSharedPointer>

class FtfDocument
{
protected:
    QSharedPointer<FtfElement<TEXT>> text;
    QSharedPointer<Questions> questions;
public:
    FtfDocument();
    QSharedPointer<FtfElement<TEXT>> getText();
    QSharedPointer<Questions> getQuestions();
};

#endif // FTFDOCUMENT_H

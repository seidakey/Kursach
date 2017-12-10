#ifndef DOCUMENTDAO_H
#define DOCUMENTDAO_H

#include "FtfText/ftfdocument.h"

class DocumentDao
{
public:
    DocumentDao() = delete;
    static FtfDocument *getDocument();
    static QSharedPointer<Questions> getQuestions();
    static QSharedPointer<FtfElement<TEXT>> getText();
};

#endif // DOCUMENTDAO_H

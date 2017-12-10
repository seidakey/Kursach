#include "documentdao.h"
#include "Data/documentdata.h"

FtfDocument *DocumentDao::getDocument()
{
    return DocumentData::getDocument();
}

QSharedPointer<Questions> DocumentDao::getQuestions()
{
    return DocumentData::getDocument()->getQuestions();
}

QSharedPointer<FtfElement<TEXT>> DocumentDao::getText()
{
    return DocumentData::getDocument()->getText();
}

#ifndef QUESTIONPOINTER_H
#define QUESTIONPOINTER_H

#include "FtfText/AbstractElement/ftfelement.h"
#include "FtfText/AbstractElement/ftfmediumelement.h"

template<>
class FtfElement<QUESTION_POINTER> : public FtfMediumElement<true, false, false>
{
public:
    FtfTag getTag()
    {
        return QUESTION_POINTER;
    }
};

#endif // QUESTIONPOINTER_H

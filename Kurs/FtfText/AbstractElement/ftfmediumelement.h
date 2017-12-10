#ifndef FTFMEDIUMELEMENT_H
#define FTFMEDIUMELEMENT_H

#include "ftfabstractelement.h"

const bool hasAttributes = true;
const bool noAttributes = false;
const bool hasElements = true;
const bool noElements = false;
const bool hasText = true;
const bool noText = false;

template<bool hasAttributesParam, bool hasElementsParam, bool hasTextParam>
class FtfMediumElement : public FtfAbstractElement
{
public:
    FtfMediumElement()
    {
        attributes = new FtfAttributesModule<hasAttributesParam>;
        elements = new FtfElementsModule<hasElementsParam>;
        text = new FtfTextModule<hasTextParam>;
    }
};

#endif // FTFMEDIUMELEMENT_H

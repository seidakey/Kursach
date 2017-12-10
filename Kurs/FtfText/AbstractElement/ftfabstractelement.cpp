#include "ftfabstractelement.h"

FtfAbstractElement::~FtfAbstractElement()
{
    delete attributes;
    delete elements;
    delete text;
}

QString FtfAbstractElement::getHtml()
{
    return "";
}

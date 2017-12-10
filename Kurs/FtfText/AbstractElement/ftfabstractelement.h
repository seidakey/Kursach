#ifndef FTFABSTRACTELEMENT_H
#define FTFABSTRACTELEMENT_H

#include "FtfText/ftftag.h"
#include "ftfattributesmodule.h"
#include "ftfelementsmodule.h"
#include "ftftextmodule.h"

class FtfAbstractElementsModule;
template<bool hasElements>
class FtfElementsModule;

class FtfAbstractElement
{
public:
    FtfAbstractAttributesModule *attributes = NULL;
    FtfAbstractElementsModule *elements = NULL;
    FtfAbstractTextModule *text = NULL;
    virtual ~FtfAbstractElement();
    virtual FtfTag getTag() = 0;
    virtual QString getHtml();
};

#endif // FTFELEMENT_H

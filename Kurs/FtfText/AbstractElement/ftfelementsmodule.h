#ifndef FTFELEMENTSMODULE_H
#define FTFELEMENTSMODULE_H

#include <QVector>
#include <QString>
#include <QLoggingCategory>
#include "ftfabstractelement.h"
#include <QSharedPointer>

class FtfAbstractElement;

class FtfAbstractElementsModule
{
public:
    virtual bool hasImplementation() = 0;
    virtual void addElement(QSharedPointer<FtfAbstractElement> element) = 0;
    virtual QVector<QSharedPointer<FtfAbstractElement>> *getElements() = 0;
    virtual ~FtfAbstractElementsModule() {}
};

template<bool hasElements>
class FtfElementsModule : public FtfAbstractElementsModule
{
public:
    bool hasImplementation()
    {
        return false;
    }
    void addElement(QSharedPointer<FtfAbstractElement> element)
    {
        Q_UNUSED(element);
        qCritical() << "Element adding not supported.";
    }
    QVector<QSharedPointer<FtfAbstractElement>> *getElements()
    {
        qCritical() << "Elements getting not supported.";
        return NULL;
    }
};

template<>
class FtfElementsModule<true> : public FtfAbstractElementsModule
{
protected:
    QVector<QSharedPointer<FtfAbstractElement>> element_v;
public:
    bool hasImplementation()
    {
        return true;
    }
    void addElement(QSharedPointer<FtfAbstractElement> element)
    {
        element_v.append(element);
    }
    QVector<QSharedPointer<FtfAbstractElement>> *getElements()
    {
        return &element_v;
    }
};

#endif // FTFELEMENTSMODULE_H

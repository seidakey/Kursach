#ifndef FTFATTRIBUTESMODULE_H
#define FTFATTRIBUTESMODULE_H

#include <QMap>
#include <QString>
#include <QLoggingCategory>

class FtfAbstractAttributesModule
{
public:
    virtual bool hasImplementation() = 0;
    virtual void addAttribute(const QString &name, const QString &value) = 0;
    virtual const QMap<QString, QString> *getAttributes() = 0;
    virtual ~FtfAbstractAttributesModule() {}
};

template<bool hasAttributesParam>
class FtfAttributesModule : public FtfAbstractAttributesModule
{
public:
    bool hasImplementation()
    {
        return false;
    }
    void addAttribute(const QString &name, const QString &value)
    {
        Q_UNUSED(name)
        Q_UNUSED(value)
        qCritical() << "Attribute adding not supported.";
    }
    const QMap<QString, QString> *getAttributes()
    {
        qCritical() << "Attributes getting not supported.";
        return NULL;
    }
};

template<>
class FtfAttributesModule<true> : public FtfAbstractAttributesModule
{
protected:
    QMap<QString, QString> attribute_m;
public:
    bool hasImplementation()
    {
        return true;
    }
    void addAttribute(const QString &name, const QString &value)
    {
        attribute_m.insert(name, value);
    }
    const QMap<QString, QString> *getAttributes()
    {
        return &attribute_m;
    }
};

#endif // FTFATTRIBUTESMODULE_H

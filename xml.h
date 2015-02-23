#ifndef XML_H
#define XML_H

#include <QString>

typedef struct _Machine {
    QString name, login, server, privateKey, publicKey;
} Machine;

typedef QList<Machine> MachineList;


class Xml
{
private:
    int firstElem;

public:
    QString tag;

    Xml(const char *fileName);
    int getIndexFirstElem();
};

class CXml : public Xml
{
public:
    CXml(const char *fileName);
};

class PXml : public Xml
{
public:
    PXml(const char *fileName);
};

class QXml : public Xml
{
public:
    QXml(const char *fileName);
};

#endif // XML_H

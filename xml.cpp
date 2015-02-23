#include "xml.h"

Xml::Xml(const char *fileName)
{

}

CXml::CXml(const char *fileName)
    : Xml(fileName)
{
    tag = "connecting";
}

PXml::PXml(const char *fileName)
    : Xml(fileName)
{
    tag = "program";
}

QXml::QXml(const char *fileName)
    : Xml(fileName)
{
    tag = "queue";
}
//machineList = xml.getList();
//int firstElem = xml.getIndexFirstElem();
//machine = machineList.at(firstElem);

/*
QDomDocument domDoc;
QFile file("/home/chert/qt/forms/a.xml");
if(file.open(QIODevice::ReadOnly)) {
    if (domDoc.setContent(&file)) {
        qDebug() << "work";
        QDomElement domElement = domDoc.documentElement();
        QDomNode domNode = domElement;
        while(!domNode.isNull()) {
            QDomNode domNodeChild = domNode.firstChild();
            while(!domNodeChild.isNull()) {
                QDomElement domElem = domNode.toElement();
                if(!domElem.isNull()) {
                    qDebug() << domElem.tagName() << " " << domElem.text();
                }
                domNodeChild = domNodeChild.childNodes();
            }
            domNode.nextSibling();
        }
    }
    file.close();
}
*/

/*
machine.name = "lomonosov";
machine.login = "vladisalv_251923";
machine.server = "compiler.lomonosov.parallel.ru";
machine.privateKey = "/home/chert/.ssh/id_rsa";
machine.publicKey = "/home/chert/.ssh/id_rsa.pub";
machineList.push_back(machine);
*/


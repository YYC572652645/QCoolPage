#ifndef XMLDATAMODEL_H
#define XMLDATAMODEL_H

#include <QObject>
#include <QDomDocument>
#include <QDomElement>
#include <QMap>

typedef struct RootData
{
    QString rootString;
    QMap<QString, QString>mapAttribute;
}RootData;

typedef struct ElementData
{
    QString userNumber;
    QString userName;
    QString userSex;
    QString userGroup;
}ElementData;

class XmlDataModel
{
public:
    XmlDataModel();
    void addRootNode(const RootData &rootData);
    void appendElement(const ElementData &elementData);
    bool saveXmlData(const QString &fileName);
protected:
    QDomDocument mainDocument;
};

#endif // XMLDATAMODEL_H

#include "xmldatamodel.h"
#include "xmlreadwrite.h"
#include "xmldatadef.h"

XmlDataModel::XmlDataModel()
{

}

void XmlDataModel::addRootNode(const RootData &rootData)
{
    QDomProcessingInstruction instructionData = mainDocument.createProcessingInstruction(XmlSpace::XML_STRING, XmlSpace::VERSION_ENCODING);
    mainDocument.appendChild(instructionData);

    QDomElement rootElement = mainDocument.createElement(rootData.rootString);
    for(auto iter = rootData.mapAttribute.begin(); iter != rootData.mapAttribute.end(); iter++)
    {
        rootElement.setAttribute(iter.key(), iter.value());
    }
    mainDocument.appendChild(rootElement);
}

void XmlDataModel::appendElement(const ElementData &elementData)
{
    QDomElement userElement =  mainDocument.createElement(XmlSpace::USER_DATA);

    {
        QDomElement domElement = mainDocument.createElement(XmlSpace::USER_NUMBER);
        QDomText textData = mainDocument.createTextNode(elementData.userNumber);
        domElement.appendChild(textData);
        userElement.appendChild(domElement);
    }

    {
        QDomElement domElement = mainDocument.createElement(XmlSpace::USER_NAME);
        QDomText textData = mainDocument.createTextNode(elementData.userName);
        domElement.appendChild(textData);
        userElement.appendChild(domElement);
    }

    {
        QDomElement domElement = mainDocument.createElement(XmlSpace::USER_SEX);
        QDomText textData = mainDocument.createTextNode(elementData.userSex);
        domElement.appendChild(textData);
        userElement.appendChild(domElement);
    }

    {
        QDomElement domElement = mainDocument.createElement(XmlSpace::USER_GROUP);
        QDomText textData = mainDocument.createTextNode(elementData.userNumber);
        domElement.appendChild(textData);
        userElement.appendChild(domElement);
    }

    mainDocument.documentElement().appendChild(userElement);
}

bool XmlDataModel::saveXmlData(const QString &fileName)
{
    return writeXmlData(mainDocument, fileName);
}

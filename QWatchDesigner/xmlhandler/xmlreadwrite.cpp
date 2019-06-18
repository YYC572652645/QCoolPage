#include "xmlreadwrite.h"
#include <QFile>
#include <QTextStream>

QDomDocument readXmlData(const QString &xmlFilePath)
{

}

bool writeXmlData(const QDomDocument &domDocument, const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) return false;
    QTextStream out(&file);
    out.setCodec("UTF-8");
    domDocument.save(out, 4, QDomNode::EncodingFromTextStream);
    file.close();
    return true;
}

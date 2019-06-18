#include <QDomDocument>
#include <QDomElement>

extern QDomDocument readXmlData(const QString &xmlFilePath);
extern bool writeXmlData(const QDomDocument &domDocument, const QString &fileName);

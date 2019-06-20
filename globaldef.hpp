#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP
#include <QString>
#include <QDebug>
#include <QFile>

#ifndef LOADQSS
#define LOADQSS(qssFile)                        \
{                                               \
    QString strQss;                             \
    QFile file(qssFile);                        \
    file.open(QFile::ReadOnly);                 \
    if(file.isOpen())                           \
    {                                           \
        strQss = QLatin1String(file.readAll()); \
        qDebug()<<strQss;                       \
        qApp->setStyleSheet(strQss);            \
        file.close();                           \
    }                                           \
}
#endif

#ifndef SAFEDELETE
#define SAFEDELETE(pointer) \
{                           \
    if(pointer)             \
    {                       \
        delete pointer;     \
    }                       \
    pointer = NULL;         \
}
#endif

namespace GlobalSpace
{
const QString BLACK_QSS_FILE_PATH = ":/res/res/stylesheet/black.qss";
}
#endif // GLOBALDEF_HPP

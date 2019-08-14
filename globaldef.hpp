#ifndef GLOBALDEF_HPP
#define GLOBALDEF_HPP
#include <QString>
#include <QDebug>
#include <QFile>

#ifndef LOADQSS
#define LOADQSS(qssFile)                        \
{                                               \
    QFile file(qssFile);                        \
    file.open(QFile::ReadOnly);                 \
    if(file.isOpen())                           \
    {                                           \
        qApp->setStyleSheet(file.readAll());    \
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
pointer = nullptr;          \
}
#endif

enum WidgetTabType
{
    TAB_BANNA,
    TAB_CYLINDER,
    TAB_MAX,

};
namespace GlobalSpace
{
const QString BLACK_QSS_FILE_PATH = ":/res/res/stylesheet/black.qss";
}
#endif // GLOBALDEF_HPP

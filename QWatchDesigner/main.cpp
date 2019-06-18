#include "qwatchdesigner.h"
#include <QApplication>
#include "globaldef.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LOADQSS(GlobalSpace::BLACK_QSS_FILE_PATH);
    QWatchDesigner w;
    w.show();

    return a.exec();
}

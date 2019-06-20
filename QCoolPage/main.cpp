#include "mainwindow.h"
#include <globaldef.hpp>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    LOADQSS(GlobalSpace::BLACK_QSS_FILE_PATH);
    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include <globaldef.hpp>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainwindow;
    LOADQSS(GlobalSpace::STYLE_QSS_FILE_PATH);
    mainwindow.showNormal();

    return a.exec();
}

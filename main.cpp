#include "mainwindow.h"
#include <globaldef.hpp>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    MainWindow mainwindow;
    LOADQSS(GlobalSpace::BLACK_QSS_FILE_PATH);
    mainwindow.showNormal();

    return a.exec();
}

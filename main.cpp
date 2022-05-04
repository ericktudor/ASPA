#include "mainwindow.h"
#include "system.h"

#include <QApplication>

System *System::instance=nullptr;
int main(int argc, char *argv[])
{
    System& mysys=System::getInstance();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

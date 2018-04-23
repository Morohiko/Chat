#include "mainwindow.h"
//#include "client.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow *mw = new MainWindow();

    return a.exec();
}

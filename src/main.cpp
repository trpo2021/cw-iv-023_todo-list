#include "MainWindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MyMainWindow w;

    w.setFixedSize(1024, 720);
    w.setWindowTitle("ToDoList");
    w.show();
    return a.exec();
}

#include "ToDoList.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    ToDoList window;
    window.show();
    return app.exec();
}
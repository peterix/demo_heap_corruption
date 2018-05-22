#include "poc_heap_corruption.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    poc_heap_corruption w;
    w.show();

    return app.exec();
}


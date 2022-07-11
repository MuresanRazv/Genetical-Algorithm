#include "UI.h"
#include <random>

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    UI ui;
    ui.show();

    return a.exec();
}

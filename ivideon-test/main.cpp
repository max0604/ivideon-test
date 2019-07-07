#include "led.h"
#include <QApplication>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Led w;

    qDebug() << w.setColor(5);

    w.show();

    return a.exec();
}

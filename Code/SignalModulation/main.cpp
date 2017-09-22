#include "signalmodulation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignalModulation w;
    w.show();

    return a.exec();
}

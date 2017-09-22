#ifndef SIGNALMODULATION_H
#define SIGNALMODULATION_H

#include <QMainWindow>

namespace Ui {
class SignalModulation;
}

class SignalModulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignalModulation(QWidget *parent = 0);
    ~SignalModulation();

private:
    Ui::SignalModulation *ui;
};

#endif // SIGNALMODULATION_H

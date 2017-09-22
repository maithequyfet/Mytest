#include "signalmodulation.h"
#include "ui_signalmodulation.h"

SignalModulation::SignalModulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalModulation)
{
    ui->setupUi(this);
}

SignalModulation::~SignalModulation()
{
    delete ui;
}

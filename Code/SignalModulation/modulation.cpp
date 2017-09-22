#include <signal_define.h>

void InitialSourceSignal(Signal *sig){
    sig->type = eSin;
    sig->fre = 5000; /* Frequency is 5kHz */
    sig->ampl = 150;
    sig->phaseOff = 0;
}


void InitialPWMSignal(Signal *sig){
    sig->type = eSawTooth;
    sig->fre = 80000; /*Frequency is 80kHz */
    sig->ampl = 150;
    sig->phaseOff = 0;
}


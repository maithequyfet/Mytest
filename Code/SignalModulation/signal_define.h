#ifndef SIGNAL_DEFINE_H
#define SIGNAL_DEFINE_H

#define PI 3.141592653589793
#define TWO_PI 6.28318530717958
#define SAMPLE_RATE 200000 /* 200 kHz */

typedef enum _eSignalType{
    eSin = 0 ,              /* Sin wave */
    eSquare,                /* Square wave */
    eSawTooth,              /* Sawtooth wave */
    eRamp,                  /* Ramp wave */
    eTriAngle               /* Triangle wave */
}eSignalType;

typedef struct _Signal{
    /*Type of wave*/
    eSignalType type;
    /* Duration */
    unsigned int fre;
    /* Amplitude */
    double ampl;
    /* Phase */
    double phaseOff;
}Signal;

/* Comput only one preiod of a signal */
double* GenSinWave(Signal sig, unsigned int sampleRate);

double* GenSquareWave(Signal sig, unsigned int sampleRate);

double* GenSawToothWave(Signal sig, unsigned int sampleRate);

double* GenRampWave(Signal sig, unsigned int sampleRate);

double* GenTriAngleWave(Signal sig, unsigned int sampleRate);




#endif // SIGNAL_DEFINE_H

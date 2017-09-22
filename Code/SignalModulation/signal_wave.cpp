#include <cmath>
#include "signal_define.h"

double* GenSinWave(Signal sig, unsigned short sampleRate){
    /* The number sample that will be generated */
    unsigned int totalSample = sampleRate / sig.fre;
    /*The buffer in which the samples will be stored. */
    double* buffer = new double[totalSample];
    // Initial phase counter. This variable can be seen as phi.
    double phase  = 0;
    double frequency = sig.fre;

    double phaseIncrement = frequency * TWO_PI / sampleRate;

    for(unsigned int i = 0; i < totalSample; i++){
        buffer[i] = sig.ampl * sin(phase);
        phase += phaseIncrement;
        if(phase >= TWO_PI){
            phase -= phase;
        }
    }
    return buffer;
}

double* GenSquareWave(Signal sig, unsigned int sampleRate){
    unsigned int totalSample = sampleRate / sig.fre;
    /*The buffer in which the samples will be stored. */
    double* buffer = new double[totalSample];

    /* the midpoint of the period => 1/2 of period */
    double mid = 0.5;

    double value = 0;

    for(unsigned int i = 0; i < totalSample; i++){
        if(value < mid){
            buffer[i] = sig.ampl;
        }else{
            buffer[i] = -sig.ampl;
        }
    }
    return buffer;
}

double* GenSawToothWave(Signal sig, unsigned int sampleRate){
    unsigned int totalSample = sampleRate / sig.fre;
    /*The buffer in which the samples will be stored. */
    double *buffer = new double[totalSample];

     double dur = 1/sig.fre;
    /* Increament of sawtooth signal */
    double incr = -2.0 / dur;
    double value = sig.ampl;

    for(unsigned int i = 0; i < totalSample; i++){
        buffer[i] = value;
        value += incr;
    }
    return buffer;
}

double* GenRampWave(Signal sig, unsigned int sampleRate){
   unsigned int totalSample = sampleRate / sig.fre;
    /*The buffer in which the samples will be stored. */
    double *buffer = new double[totalSample];

    double dur = 1/sig.fre;
    /* Increamentb of ramp wave */
    double incr = 2.0 / dur;
    double value = sig.ampl;
    for(unsigned int i = 0; i < totalSample; i++){
        buffer[i] = value;
        value += incr;
    }

    return buffer;
}

//double* GenTriAngleWave(Signal sig){
//    /* The number sample that will be generated */
//    unsigned int totalSample = sig.dur * sampleRate;
//
//}

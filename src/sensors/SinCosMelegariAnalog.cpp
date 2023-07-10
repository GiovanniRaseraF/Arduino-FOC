#include "SinCosMelegariAnalog.h"

SinCosMelegariAnalog::SinCosMelegariAnalog(
    uint8_t _pinSin, uint8_t _pinCos, int _minSinVal, int _maxSinVal, int _minCosVal, int _maxCosVal){
    
    pinSin = _pinSin;
    pinCos = _pinCos;

    // setup offset, use empirical results
    minSinVal = (_minSinVal >= 0 && _minSinVal < _maxSinVal && _minSinVal < ADCMAX) ? _minSinVal : 0;
    minCosVal = (_minCosVal >= 0 && _minCosVal < _maxCosVal && _minCosVal < ADCMAX) ? _minCosVal : 0;

    maxSinVal = (_minSinVal < ADCMAX && _maxSinVal >= 0) ? _maxSinVal : ADCMAX;
    maxCosVal = (_minCosVal < ADCMAX && _maxCosVal >= 0) ? _maxCosVal : ADCMAX;

    pinMode(pinSin, INPUT);
    pinMode(pinCos, INPUT);
}

void SinCosMelegariAnalog::init(){
    this->Sensor::init();
}

float SinCosMelegariAnalog::getSensorAngle(){
    int sin = analogRead(pinSin);
    int cos = analogRead(pinCos);

    // convert to rads
    sin = (sin - minSinVal);
    float sintoone = (float)sin / ((float)maxSinVal / 2) - 1;

    cos = (cos - minCosVal);
    float costoone = (float)cos / ((float)maxCosVal / 2) - 1;

    float angle = atan(sintoone / costoone);

    return angle;
}
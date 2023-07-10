#ifndef SINCOSMELEGARIANALOG_LIB_H
#define SINCOSMELEGARIANALOG_LIB_H

#include <Arduino.h>
#include "../common/base_classes/Sensor.h"
#include "../common/foc_utils.h"
#include "../common/time_utils.h"

#define ADCMAX 1024

class SinCosMelegariAnalog : public Sensor {
    public:
    // Operation range in Arduino UNO is 0 to 1023, because ADC precision is 10 bit
    SinCosMelegariAnalog(uint8_t _pinSin, uint8_t _pinCos, int _minSinVal, int _maxSinVal, int _minCosVal, int _maxCosVal);

    protected:
    virtual float getSensorAngle() override;
    virtual float init() override;

    uint8_t pinSin = A0;
    uint8_t pinCos = A1;
    int minSinVal = 0;
    int maxSinVal = 1023;
    int minCosVal = 0;
    int maxCosVal = 1023;
};

#endif
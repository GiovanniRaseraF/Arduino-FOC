#ifndef SINCOSMELEGARIANALOG_LIB_H
#define SINCOSMELEGARIANALOG_LIB_H

#include <Arduino.h>
#include "../common/base_classes/Sensor.h"
#include "../common/foc_utils.h"
#include "../common/time_utils.h"

class SinCosMelegariAnalog : public Sensor {
    public:
    // Operation range in Arduino UNO is 0 to 1023, because ADC precision is 10 bit
    SinCosMelegariAnalog(int _pinSin, int _pinCos, int _minSinVal, int _maxSinVal, int _minCosVal, int _maxCosVal);

    virtual float getAngle() override;

    virtual float getVelocity() override;

    virtual int32_t getFullRotations() override;

    virtual void update() override;

    protected:
    virtual float getSensorAngle() override;
    virtual float init() override;

    int pinSin = A0;
    int pinCos = A1;
    int minSinVal = 0;
    int maxSinVal = 1024;
    int minCosVal = 0;
    int maxCosVal = 1024;
};

#endif
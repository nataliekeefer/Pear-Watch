#ifndef PearWatchPower_h
#define PearWatchPower_h

//standard arduino libraries
#include <Arduino.h>


class PearWatchPower
{
  private:

  public:
    bool isCharging();
    uint16_t getBatteryVoltage();
};

#endif

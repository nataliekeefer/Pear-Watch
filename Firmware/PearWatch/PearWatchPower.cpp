bool PearWatch::isCharging()
{
  digitalRead(pin_); //this is going to read the status pin, if the pin is on, its not charging
}

uint16_t PearWatch::getBatteryVoltage()
{
  
}

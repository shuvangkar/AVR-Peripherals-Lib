#ifndef _ADC_H_
#define _ADC_H_
#include <Arduino.h>

/**************Macro definition for ADC Auto Trigger source**********/
#define FREE_RUNNING 0b000
#define TIMER1_CMP_B 0b101


class Adc
{
  public :
    void begin();
    void attachInterrupt(void (*isr)() = NULL); 
    void detachInterrupt();
    void setChannel(byte channel);
    void setAutoTriggerSource(byte source);
    void startConversion(byte channel = 0);
    void (*isrCallback)();            //Function pointer for interrupt routine

    uint16_t read(byte channel);
    float readAverage(byte channel, byte N)
    float getAvcc();
	
};

extern Adc adc;
#endif
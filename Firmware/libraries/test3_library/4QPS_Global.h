#ifndef _4QPS_GLOBAL_H_
#define _4QPS_GLOBAL_H_

#include <EventManager.h>
#include <TaskManager.h>
#include <4QPS_OTA.h>
#include <4QPS_ADC.h>
#include <4QPS_DAC.h>
#include <4QPS_Encoder.h>
#include <4QPS_Display.h>
#include <4QPS_TC1047A.h>
#include "..\..\test3.h"

extern EventManager eMgr;
extern Display disp;
extern RotaryEncoder rotary;
extern DAC dac;
extern ADC adc;
extern TemperatureSensor ts;
extern double Vset;
extern double Isnk;
extern double Isrc;

#endif // End _4QPS_GLOBAL_H_
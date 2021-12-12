// CHOOSE Board: ESP32 DEV MODULE in Arduino
// https://github.com/igormiktor/arduino-EventManager
// https://github.com/hideakitai/TaskManager


// Connect to Access Point "4QPS" and visit 192.168.4.1 to store you network SSID/password in EEPROM before fist use.
#ifndef USE_OTA
// #define USE_OTA  // Comment this line to disable OTA firmware update if no wireless network is available.
#endif

//#include <Arduino.h>
#include <EventManager.h>
#include <TaskManager.h>
#include "4QPS_OTA.h"
#include <4QPS_ADC.h>
#include <4QPS_DAC.h>
#include <4QPS_Encoder.h>
#include <4QPS_Display.h>
#include <4QPS_TC1047A.h>
#include <menu.h>
#include "test3.h"

#ifdef USE_OTA
OTA ota;
#endif

EventManager eMgr;
Display disp;
RotaryEncoder rotary;
DAC dac;
ADC adc;
TemperatureSensor ts;
MenuMain menuMain;
MenuNext menuNext;
MENU menu=MENU_MAIN;
double Vset=0.0;
double Isnk=0.1;
double Isrc=0.1;

void CW(){eMgr.queueEvent( EventManager::kEventUser0, 1);}
void CCW(){eMgr.queueEvent( EventManager::kEventUser0, 2);}
void PB(){eMgr.queueEvent( EventManager::kEventUser0, 3);}

void listener( int event, int param )
{
switch (event) {
    case EventManager::kEventUser0: {
      MENU last_menu=menu;
      switch (menu) {
        case MENU_MAIN: menu=menuMain.handler(param); break;
        case MENU_NEXT: menu=menuNext.handler(param); break;
        default:;
      }
      if (menu!=last_menu) eMgr.queueEvent( EventManager::kEventUser0, 0);
      break;
    }
    case EventManager::kEventUser1: {
      disp.updateVI(adc.readVoltage(),adc.readCurrent());
      break;
    }
    case EventManager::kEventUser2: {
#ifdef USE_OTA
      ota.begin();
#endif      
      break;
    }    
    default:;
  }
}


void setup()
{
  pinMode(EPC_4QPS_T1, INPUT);
  pinMode(EPC_4QPS_TSD, INPUT);
  pinMode(EPC_4QPS_ISNK, INPUT);
  pinMode(EPC_4QPS_ISRC, INPUT);
  pinMode(EPC_4QPS_EN, OUTPUT); digitalWrite(EPC_4QPS_EN,LOW);
  pinMode(EPC_4QPS_T2, INPUT);      

  rotary.set_callbackCW(&CW);
  rotary.set_callbackCCW(&CCW);
  rotary.set_callbackPB(&PB);

  dac.begin();
  dac.setIsnk(Isnk);
  dac.setIsrc(Isrc);
  dac.setVoltage(Vset);
  adc.begin();
  disp.begin();
  eMgr.addListener( EventManager::kEventUser0, listener);  // Task 0: Handling Menus
  eMgr.addListener( EventManager::kEventUser1, listener);  // Task 1: Displaying VI
  eMgr.queueEvent( EventManager::kEventUser0, 0);  // begin Menu
#ifdef USE_OTA
  eMgr.addListener( EventManager::kEventUser2, listener);  // Task 2: Handling OTA (Over the Air WiFi firmware update)
  eMgr.queueEvent( EventManager::kEventUser2, 0);  // begin.OTA
#endif
  digitalWrite(EPC_4QPS_EN,HIGH);
}

void loop(void) {
#ifdef USE_OTA
  ota.handle(); 
#endif
  eMgr.processEvent();
  Tasks.update();  
}

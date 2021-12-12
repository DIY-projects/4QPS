#ifndef _4QPS_DISPLAY_H
#define _4QPS_DISPLAY_H

#include "Arduino.h"
#include "TFT_eSPI.h"
#include "Free_Fonts.h"


extern double Vset;
extern double Isrc;
extern double Isnk;

//#include <primitives.h>

//#define SYSTEM_FONT FSB12 //was FSB18
#define TFT_BL  26


/*
// 4QPS TFT LCD conntion pinouts
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS   15  // Chip select control pin
#define TFT_DC   33  // Data Command control pin
*/

#define HEADER_BACKGROUND_COLOR		TFT_NAVY
#define HEADER_TEXT_COLOR					TFT_DARKGREY
#define BACKGROUND_COLOR					TFT_BLUE
#define TEXT_HIGHLIGHT_COLOR			TFT_WHITE
#define TEXT_COLOR								TFT_DARKGREY
#define HEADER_FONT								FSB18
#define	TEXT_FONT									FSB12
#define	VI_FONT										FSB18
#define VI_COLOR									TFT_WHITE
#define	ISRCISNK_FONT							FSB12
#define CENTER_TAB								lcd_width/2
#define LABEL_TAB									10
#define VALUE_TAB									60
#define VALUE_TAB_2								70

typedef enum {VSET,ISRC,ISNK} TypeStates;

class Display
{
  public:
  TFT_eSPI tft;
  int lcd_width, lcd_height;
  unsigned long drawTime;
  int counter;
	uint32_t line(int);
	
    Display(void);
    void begin(void);
    void showMenuMain(void);
    void showMenuNext(void);
		void updateIsrc(double);
		void updateIsnk(double);
		void updateSetVoltage(double);
		void updateVI(float, float);
		void updateTemperature(int, int, int);
		void updateInteger(int,int,int);
		void updateStr(const char*,int,int);
		void updateGroupVII(TypeStates);
		void updateVII(TypeStates);
};


#endif
#include "Arduino.h"
#include "4QPS_DISPLAY.h"

Display::Display() {};

uint32_t Display::line(int line) { return (uint32_t)lcd_height/10*line+2;}

void Display::begin()
{
  drawTime = 0;
  counter = 0;
  pinMode (TFT_BL, OUTPUT);
  digitalWrite (TFT_BL, HIGH);
  tft.init();
  tft.setRotation(0);
  if (tft.getRotation()%2)
  {
    lcd_width=tft.height();
    lcd_height=tft.width();
  }
  else  
  {
    lcd_width=tft.width();
    lcd_height=tft.height();
   }
}

void Display::showMenuMain()
{
  tft.setFreeFont(HEADER_FONT);
  tft.fillScreen(BACKGROUND_COLOR);
	tft.fillRect(0, 0, lcd_width, tft.fontHeight(), HEADER_BACKGROUND_COLOR),
  tft.setTextColor(HEADER_TEXT_COLOR, HEADER_BACKGROUND_COLOR);
  tft.setTextDatum(TC_DATUM);
  tft.drawString("4QPS - Main", CENTER_TAB, line(0));
  tft.setTextDatum(TL_DATUM); // Text Datum at Top-Left
	tft.setTextColor(VI_COLOR, BACKGROUND_COLOR);
  tft.setFreeFont(VI_FONT);
	tft.drawString("V:",LABEL_TAB, line(2));
	tft.drawString("I:",LABEL_TAB, line(3));
	tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
  tft.setFreeFont(ISRCISNK_FONT);
	tft.drawString("Isrc:",LABEL_TAB, line(5));
	tft.drawString("Isnk:",LABEL_TAB, line(6));
	tft.drawString("Vset:",LABEL_TAB, line(8));

}


void Display::updateGroupVII(TypeStates state) {
  tft.setFreeFont(TEXT_FONT);
	tft.setTextPadding(lcd_width - VALUE_TAB_2);
	switch(state) {
	case VSET:
		tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isrc, 3, VALUE_TAB_2, line(5));
		tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isnk, 3, VALUE_TAB_2, line(6));
		tft.setTextColor(TEXT_HIGHLIGHT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Vset, 3, VALUE_TAB_2, line(8));
		break;
	case ISRC:
		tft.setTextColor(TEXT_HIGHLIGHT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isrc, 3, VALUE_TAB_2, line(5));
		tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isnk, 3, VALUE_TAB_2, line(6));
		tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Vset, 3, VALUE_TAB_2, line(8));
	break;
	case ISNK:
		tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isrc, 3, VALUE_TAB_2, line(5));
		tft.setTextColor(TEXT_HIGHLIGHT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isnk, 3, VALUE_TAB_2, line(6));
		tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Vset, 3, VALUE_TAB_2, line(8));
	break;
	default:;
	}
}

void Display::updateVII(TypeStates state) {
  tft.setFreeFont(TEXT_FONT);
	tft.setTextPadding(lcd_width - VALUE_TAB_2);
	switch(state) {
	case VSET:
		tft.setTextColor(TEXT_HIGHLIGHT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Vset, 3, VALUE_TAB_2, line(8));
		break;
	case ISRC:
		tft.setTextColor(TEXT_HIGHLIGHT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isrc, 3, VALUE_TAB_2, line(5));
	break;
	case ISNK:
		tft.setTextColor(TEXT_HIGHLIGHT_COLOR, BACKGROUND_COLOR);
		tft.drawFloat(Isnk, 3, VALUE_TAB_2, line(6));
	break;
	default:;
	}
}

void Display::updateVI(float V, float I)
{
	tft.setTextColor(VI_COLOR, BACKGROUND_COLOR);
  tft.setFreeFont(VI_FONT);
	tft.setTextPadding(lcd_width - VALUE_TAB);
	tft.drawFloat(V, 4, VALUE_TAB, line(2));
	tft.drawFloat(I, 4, VALUE_TAB, line(3));
}

void Display::updateTemperature(int value, int x, int y) {
	tft.setTextPadding(lcd_width-x);
  tft.drawNumber(value, x, line(y));
}

void Display::updateInteger(int value, int x, int y) {
	tft.setTextPadding(lcd_width-x);
  tft.drawNumber(value, x, line(y));
}

void Display::updateStr(const char * st, int x, int y) {
	tft.setTextPadding(lcd_width-x);
  tft.drawString(st, x, line(y));
}


/*

void Display::updateIsrc(double Isrc)
{
	tft.setTextPadding(lcd_width - VALUE_TAB_2);
	tft.drawFloat(Isrc, 4, VALUE_TAB_2, line(5));
}

void Display::updateIsnk(double Isnk)
{
	tft.setTextPadding(lcd_width - VALUE_TAB_2);
	tft.drawFloat(Isnk, 4, VALUE_TAB_2, line(6));
}

void Display::updateSetVoltage(double Vset)
{
	tft.setTextPadding(lcd_width - VALUE_TAB_2);
  tft.drawFloat(Vset, 3, VALUE_TAB_2, line(8));
}
*/
void Display::showMenuNext()
{
  tft.setFreeFont(HEADER_FONT);
  tft.fillScreen(BACKGROUND_COLOR);
	tft.fillRect(0, 0, lcd_width, tft.fontHeight(), HEADER_BACKGROUND_COLOR),
  tft.setTextColor(HEADER_TEXT_COLOR, HEADER_BACKGROUND_COLOR);
  tft.setTextDatum(TC_DATUM);
  tft.drawString("4QPS - Next", CENTER_TAB, line(0));
	tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
  tft.setTextDatum(TL_DATUM); // Text Datum at Top-Left
  tft.setFreeFont(TEXT_FONT);
}

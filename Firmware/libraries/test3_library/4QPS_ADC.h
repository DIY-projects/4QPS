#ifndef _4QPS_ADC_H
#define _4QPS_ADC_H


#include "Arduino.h"
#include "SPI.h"


#define ADC_CS    		5
#define ADC_SCK   		18
#define ADC_DOUT  		19
#define ADC_DIN   		23
#define ADC_RST   		22

#define	ADC_EXT						0
#define ADC_CURRENT_HIGH	1
#define ADC_VOLTAGE				2
#define ADC_CURRENT_LOW		3

#define VSPI_SPEED 10000000


class ADC
{
	private:
		SPIClass spiADC;
		SPISettings settingsSpiADC;
		uint32_t readADC32(uint32_t dataADC);
		void writeADC32(uint32_t dataADC);
	public:
		ADC(void);
		void begin(void);
		long readADC(int);
		float readVoltage(void);
		float readCurrent(void);
		float readCurrentLow(void);
		float readCurrentHigh(void);
};

#endif
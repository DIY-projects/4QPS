#ifndef _4QPS_DAC_H
#define _4QPS_DAC_H

#include "Arduino.h"
#include "SPI.h"


// DAC8004IPW  (Pins)
#define DAC_LD			16	// /LDAC (Pin 1)
#define DAC_CS			17  // /SYNC (Pin 2)
#define DAC_SCK   	18	// (Pin 14)
#define DAC_DOUT  	19  // (Pin N/C)  DUMMY DAC_DOUT For spi init only.
#define DAC_DIN   	23	// (Pin 13)

#define	CHANNEL_A		0
#define	CHANNEL_B		1
#define	CHANNEL_C		2
#define	CHANNEL_D		3


#define CHANNEL_VP			(CHANNEL_C << 20)	// Channel C (Pin 5)
#define CHANNEL_VN			(CHANNEL_A << 20)	// Channel A (Pin 4)
#define CHANNEL_ISNK		(CHANNEL_B << 20)	// Channel B (Pin 11)
#define CHANNEL_ISRC		(CHANNEL_D << 20)	// Channel D (Pin 10)

#define VSPI_SPEED 10000000


class DAC
{
	private:
		SPIClass spiDAC;
		SPISettings settingsSpiDAC;
		float VCsnk;
		float VCsrc;
    void update();
		void writeDAC32(uint32_t);
  public:
    DAC();
    void begin();
		void setVoltage(float);
		void setIsnk(float);
		void setIsrc(float);
};

#endif
#include "Arduino.h"
#include "4QPS_DAC.h"
#include "SPI.h"

DAC::DAC()
{
	spiDAC = SPIClass(VSPI);
	settingsSpiDAC = SPISettings(VSPI_SPEED, SPI_MSBFIRST, SPI_MODE2);
}

void DAC::begin()
{
	pinMode(DAC_LD, OUTPUT);
	digitalWrite(DAC_LD,HIGH);
	pinMode(DAC_CS, OUTPUT);
	digitalWrite(DAC_CS,HIGH);
	spiDAC.begin(DAC_SCK, DAC_DOUT, DAC_DIN, DAC_CS);
}

void DAC::writeDAC32(uint32_t dataDAC)
{
	spiDAC.beginTransaction(settingsSpiDAC);
	digitalWrite(DAC_CS, LOW);
	spiDAC.write32(dataDAC);
	digitalWrite(DAC_CS, HIGH);
	spiDAC.endTransaction();
}

void DAC::update(){
	digitalWrite(DAC_LD,LOW);
	delay(1);
	digitalWrite(DAC_LD,HIGH);
}


void DAC::setVoltage(float voltage)
{
	if (voltage>=0) {
		uint32_t data=(uint32_t)(voltage/2/5/(4.096/65536));
		data<<=4;
		data &= 0x000FFFF0;
		writeDAC32(CHANNEL_VP | data);
		writeDAC32(CHANNEL_VN | 0);
		}
	else {
		uint32_t data=(uint32_t)(-1.0*voltage/2/5/(4.096/65536));
		data<<=4;
		data &= 0x000FFFF0;
		writeDAC32(CHANNEL_VP | 0);
		writeDAC32(CHANNEL_VN | data);
		}
	update();
}


/*

// voltage was normalized (0.0~1.0)
void DAC::setVoltage(float voltage)
{
	if (voltage>=0) {
		uint32_t data=(uint32_t)(voltage*65535);
		data<<=4;
		data &= 0x000FFFF0;
		writeDAC32(CHANNEL_VP | data);
		writeDAC32(CHANNEL_VN | 0);
		}
	else {
		uint32_t data=(uint32_t)(-1.0f*voltage*65535);
		data<<=4;
		data &= 0x000FFFF0;
		writeDAC32(CHANNEL_VP | 0);
		writeDAC32(CHANNEL_VN | data);
		}
	update();
}
*/		
/*
	uint32_t data=(uint32_t)((voltage>=0?voltage:-voltage)*65536);
	data<<=4;
	if (voltage>=0) {
		writeDAC32(CHANNEL_VP | data);
		writeDAC32(CHANNEL_VN | 0);
		}
	else {
		writeDAC32(CHANNEL_VP | 0);
		writeDAC32(CHANNEL_VN | data);
		}
*/


void DAC::setIsnk(float value) {
		uint32_t data=(uint32_t)(value*65535);
		data<<=4;
		data &= 0x000FFFF0;
		writeDAC32(CHANNEL_ISNK | data);
}

void DAC::setIsrc(float value) {
		uint32_t data=(uint32_t)(value*65535);
		data<<=4;
		data &= 0x000FFFF0;
		writeDAC32(CHANNEL_ISRC | data);
}


  
/*	
void DAC::writeDAC32(uint32_t dataDAC)
{
	typedef union {
		uint32_t data32;
		unsigned char dataArray[sizeof(uint32_t)];
	} LocalData;
	LocalData d32;
	d32.data32 = dataDAC;
	spiDAC.beginTransaction(settingsSpiDAC);
	digitalWrite(DAC_CS, LOW);
	spiDAC.transfer(d32.dataArray[3]);  // ESP32 is little endian
	spiDAC.transfer(d32.dataArray[2]);
	spiDAC.transfer(d32.dataArray[1]);
	spiDAC.transfer(d32.dataArray[0]);
	digitalWrite(DAC_CS, HIGH);
	spiDAC.endTransaction();
}
*/
/*
uint32_t DAC::readDAC32(uint32_t commandDAC) {
  typedef union {
		uint32_t data32;
		unsigned char dataArray[sizeof(uint32_t)];
  } LocalData;
	LocalData c32, d32;
	c32.data32 = commandDAC;
	spiDAC.beginTransaction(settingsSpiDAC);
	digitalWrite(DAC_CS, LOW);          // Writing "Read" command
	spiDAC.transfer(c32.dataArray[3]);  // ESP32 is little endian
	spiDAC.transfer(c32.dataArray[2]);
	spiDAC.transfer(c32.dataArray[1]);
	spiDAC.transfer(c32.dataArray[0]);
	digitalWrite(DAC_CS, HIGH);
	delay(1);
	digitalWrite(DAC_CS, LOW);          // Writing "NOP" command (0x1E000000) for READ operation.
	d32.dataArray[3] = spiDAC.transfer(0x1E);  // ESP32 is little endian
	d32.dataArray[2] = spiDAC.transfer(0x00);
	d32.dataArray[1] = spiDAC.transfer(0x00);
	d32.dataArray[0] = spiDAC.transfer(0x00);
	digitalWrite(DAC_CS, HIGH);
	spiDAC.endTransaction();
	return d32.data32;
}
*/
  

#include "Arduino.h"
#include "4QPS_ADC.h"
#include "SPI.h"
#include <4QPS_Global.h>
#include "..\..\test3.h"

ADC::ADC()
{
	spiADC = SPIClass(VSPI);
	settingsSpiADC = SPISettings(VSPI_SPEED, SPI_MSBFIRST, SPI_MODE0);
}

void ADC::begin()
{
	pinMode(ADC_CS, OUTPUT);
	digitalWrite(ADC_CS,HIGH);
	spiADC.begin(ADC_SCK, ADC_DOUT, ADC_DIN, ADC_CS);
}

void ADC::writeADC32(uint32_t dataADC)
{
	digitalWrite(ADC_CS, HIGH);
	spiADC.beginTransaction(settingsSpiADC);
	digitalWrite(ADC_CS, LOW);
	spiADC.write32(dataADC);
	digitalWrite(ADC_CS, HIGH);
	spiADC.endTransaction();
}

uint32_t ADC::readADC32(uint32_t dataADC)
{
	digitalWrite(ADC_CS, HIGH);
	spiADC.beginTransaction(settingsSpiADC);
	digitalWrite(ADC_CS, LOW);
	uint32_t data = spiADC.transfer32(dataADC);
	digitalWrite(ADC_CS, HIGH);
	spiADC.endTransaction();
	return data;
}

long ADC::readADC(int channel) {
	writeADC32(channel<<26 | 0xC0000000);
	return (long)(readADC32(0)<<2) | (long)((readADC32(0)>>30)&0x00000003);
}


float ADC::readVoltage(void) {
	return (float) (adc.readADC(ADC_VOLTAGE)-131072)*(4.096/131072)*2.5*3;
}

float ADC::readCurrent(void) {
  pinMode(EPC_4QPS_IRANGE, OUTPUT); digitalWrite(EPC_4QPS_IRANGE,LOW);
	delay(1);
	return (float) (adc.readADC(ADC_CURRENT_HIGH)-131072)*(4.096/131072)*2.5/10/0.08;
}

float ADC::readCurrentLow(void) {
  pinMode(EPC_4QPS_IRANGE, OUTPUT); digitalWrite(EPC_4QPS_IRANGE,HIGH);
	delay(1);
	return (float) (adc.readADC(ADC_CURRENT_LOW)-131072)*(4.096/131072)*2.5/10/0.08;
}

float ADC::readCurrentHigh(void) {
  pinMode(EPC_4QPS_IRANGE, OUTPUT); digitalWrite(EPC_4QPS_IRANGE,LOW);
	delay(1);
	return (float) (adc.readADC(ADC_CURRENT_HIGH)-131072)*(4.096/131072)*2.5/10/4.99;
}

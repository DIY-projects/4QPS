#include "Arduino.h"
#include "4QPS_LT1970A.h"
/*
ptrFunction ptrTSD;

void IRAM_ATTR isr_ENC_A_RISING() {if (digitalRead(ENC_B)) ptrCCW(); else ptrCW();}
void IRAM_ATTR isr_ENC_A_FALLING() {if (digitalRead(ENC_B)) ptrCW(); else ptrCCW();}
void IRAM_ATTR isr_ENC_B_RISING() {if (digitalRead(ENC_A)) ptrCW(); else ptrCCW();}
void IRAM_ATTR isr_ENC_B_FALLING() {if (digitalRead(ENC_A)) ptrCCW();else ptrCW();}
void IRAM_ATTR isr_ENC_PB() {ptrPB();}

RotaryEncoder::RotaryEncoder()
{
	value = 0;
	pinMode(ENC_A, INPUT);
	pinMode(ENC_B, INPUT);
	pinMode(ENC_PB, INPUT_PULLUP);
	attachInterrupt(ENC_A, isr_ENC_A_RISING, RISING);
	attachInterrupt(ENC_A, isr_ENC_A_FALLING, FALLING);
	attachInterrupt(ENC_B, isr_ENC_B_RISING, RISING);
	attachInterrupt(ENC_B, isr_ENC_B_FALLING, FALLING);
	attachInterrupt(ENC_PB, isr_ENC_PB, FALLING);
};

void RotaryEncoder::set_ptrCW(ptrFunction pFunc) {ptrCW = pFunc;}
void RotaryEncoder::set_ptrCCW(ptrFunction pFunc) {ptrCCW = pFunc;}
void RotaryEncoder::set_ptrPB(ptrFunction pFunc) {ptrPB = pFunc;}

void RotaryEncoder::plusOne() {if (++value>100) value=100;}
void RotaryEncoder::minusOne() {if (--value<-100) value=-100;}
void RotaryEncoder::zero() {value=0;}
int RotaryEncoder::readValue() {return value;}
*/
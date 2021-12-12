#include "Arduino.h"
#include <time.h>
#include "4QPS_Encoder.h"

ptrCallback ptrCW;
ptrCallback ptrCCW;
ptrCallback ptrPB;

void IRAM_ATTR isr_ENC_A_RISING() {
	for (int i=0;i<32;i++)
		if (!digitalRead(ENC_A)) return;
	int r=1;
	do  {
		r=r<<1 | digitalRead(ENC_B);
		delayMicroseconds(1);
	} while(r!=0 && r!=-1);
	if (r) ptrCCW(); else	ptrCW();
}

void IRAM_ATTR isr_ENC_PB() {
	int r=1;
	do  {
		r=r<<1 | digitalRead(ENC_PB);
		delayMicroseconds(1);
	} while (r!=0 && r!=-1);
	ptrPB();
}

RotaryEncoder::RotaryEncoder()
{
	pinMode(ENC_A, INPUT);
	pinMode(ENC_B, INPUT);
	pinMode(ENC_PB, INPUT_PULLUP);
	attachInterrupt(ENC_A, isr_ENC_A_RISING, RISING);
	attachInterrupt(ENC_PB, isr_ENC_PB, FALLING);
};

void RotaryEncoder::set_callbackCW(ptrCallback pCallback) {ptrCW = pCallback;}
void RotaryEncoder::set_callbackCCW(ptrCallback pCallback) {ptrCCW = pCallback;}
void RotaryEncoder::set_callbackPB(ptrCallback pCallback) {ptrPB = pCallback;}


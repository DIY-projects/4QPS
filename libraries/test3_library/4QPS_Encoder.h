#ifndef _4QPS_ENCODER_H
#define _4QPS_ENCODER_H

#include "Arduino.h"
#define ENC_A 34
#define ENC_B 35
#define ENC_PB 21

typedef void (*ptrCallback)(void);

class RotaryEncoder
{
	public:
		RotaryEncoder(void);
		void set_callbackCW(ptrCallback);
		void set_callbackCCW(ptrCallback);
		void set_callbackPB(ptrCallback);
};

#endif
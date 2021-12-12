#ifndef _4QPS_TC1047A_H
#define _4QPS_TC1047A_H

//#define T1	36	// ESP32 VP pin
//#define T2	39	// ESP32 VN pin

#define T1	ADC1_CHANNEL_0	// ESP32 VP pin
#define T2	ADC1_CHANNEL_3	// ESP32 VN pin


class TemperatureSensor
{
	private:
		int	value;
	public:
		TemperatureSensor(void);
		int readTemperature(int);
};

#endif
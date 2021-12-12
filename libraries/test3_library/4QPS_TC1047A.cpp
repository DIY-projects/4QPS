#include "Arduino.h"
#include <driver/adc.h>
#include "4QPS_TC1047A.h"

TemperatureSensor::TemperatureSensor() {
	adc1_config_channel_atten(T1,ADC_ATTEN_DB_0);
	adc1_config_channel_atten(T2,ADC_ATTEN_DB_0);
	adc1_config_width(ADC_WIDTH_BIT_12);
};
int TemperatureSensor::readTemperature(int channel) {
	
	if (channel==1)	return (int)adc1_get_raw(T1);
	if (channel==2)	return (int)adc1_get_raw(T2);
	return 0;
}

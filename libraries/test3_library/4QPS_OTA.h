#ifndef __4QPS_OTA_H__
#define __4QPS_OTA_H__

#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//#include <WiFi.h>
//#include <WiFiClient.h>
#include <WebServer.h>
#include <EEPROM.h>


class OTA {
	private:
	//Variables
		int i=0;
		int statusCode;
		const char* ssid = "Default_SSID";
		const char* passphrase = "Default_Password";
		String st;
		String content;
	
		void setupWiFi(void);
		void createWebServer(void);
		void setupAP(void);
		void launchWeb(void);
		bool testWifi(void);
	public:
		OTA(void);
		void begin(void);
		void handle(void);
};


// copied from (online source) wl_definitions.h

/* Encryption modes */
enum wl_enc_type {  /* Values map to 802.11 encryption suites... */
  ENC_TYPE_WEP  = 5,
  ENC_TYPE_TKIP = 2,
  ENC_TYPE_CCMP = 4,
  /* ... except these two, 7 and 8 are reserved in 802.11-2007 */
  ENC_TYPE_NONE = 7,
  ENC_TYPE_AUTO = 8,
  ENC_TYPE_UNKNOW = 255
};


#endif // __4QPS_OTA_H__
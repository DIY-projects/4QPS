#ifndef _MENU_H_
#define _MENU_H_

#include <4QPS_Global.h>

typedef enum{MENU_MAIN, MENU_NEXT} MENU;

class MenuMain{
	public:
		MenuMain(void);
		void onCW(void);
		void onCCW(void);
		void onPB(void);
		void onEnter();
		void onExit();
		MENU handler(int);
};

class MenuNext {
	public:
		MenuNext(void);
		void onCW(void);
		void onCCW(void);
		void onPB(void);
		void onEnter();
		void onExit();
		MENU handler(int);
};



#endif // _MENU_H
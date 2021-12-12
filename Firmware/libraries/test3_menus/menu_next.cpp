#include <menu.h>

const char str_CW[]="CW";
const char str_CCW[]="CCW";
const char str_BLANK[]="";


MenuNext::MenuNext(){}

void MenuNext::onEnter(){
  disp.showMenuNext();
}

void MenuNext::onExit(){
//	eMgr.queueEvent( EventManager::kEventUser0, 0);
}

void MenuNext::onCW(void){
	disp.updateStr(str_CW,80,5);
};

void MenuNext::onCCW(void){
	disp.updateStr(str_CCW,80,5);
};

void MenuNext::onPB(void){
	disp.updateStr(str_BLANK,80,5);
};

MENU MenuNext::handler(int e){
	switch (e) {
		case 0: onEnter(); break;
		case 1: onCW(); break;
		case 2: onCCW(); break;
		case 3: onPB(); onExit(); return MENU_MAIN;
		default:;
	}
	return MENU_NEXT;
}
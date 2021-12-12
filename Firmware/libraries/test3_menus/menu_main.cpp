#include <menu.h>
#include <4QPS_Global.h>
#include <4QPS_Display.h>

TypeStates vstate;

MenuMain::MenuMain(){}

void MenuMain::onEnter(){
	vstate=VSET;
  disp.showMenuMain();
	disp.updateGroupVII(vstate);
  Tasks.add("ShowVI", []{eMgr.queueEvent( EventManager::kEventUser1,0);})->startFps(4);
}

	
void MenuMain::onExit(){
	Tasks.erase("ShowVI");
}

void MenuMain::onCW(void){
 switch (vstate) {
		case VSET:
			Vset = Vset + 0.1;
			if (Vset > V_LIMIT) Vset = V_LIMIT;
			dac.setVoltage((float)Vset);
			break;
		case ISRC:
			Isrc = Isrc + 0.1;
			if (Isrc > ISRC_LIMIT) Isrc = ISRC_LIMIT;
			dac.setIsrc((float)Isrc);
			break;
		case ISNK:
			Isnk = Isnk + 0.1;
			if (Isnk > ISNK_LIMIT) Isnk = ISNK_LIMIT;
			dac.setIsnk((float)Isnk);
			break;
			default:;
	}
	disp.updateVII(vstate);
}

void MenuMain::onCCW(void){
 switch (vstate) {
		case VSET:
			Vset = Vset - 0.1;
			if (Vset < -1.0*V_LIMIT) Vset = -1.0*V_LIMIT;
			dac.setVoltage((float)Vset);
			break;
		case ISRC:
			Isrc = Isrc - 0.1;
			if (Isrc < -1.0*ISRC_LIMIT) Isrc = -1.0*ISRC_LIMIT;
			dac.setIsrc((float)Isrc);
			break;
		case ISNK:
			Isnk = Isnk - 0.1;
			if (Isnk < -1.0*ISNK_LIMIT) Isnk = -1.0*ISNK_LIMIT;
			dac.setIsnk((float)Isnk);
			break;
		default:;
	}
	disp.updateVII(vstate);
}

void MenuMain::onPB(void){
	switch(vstate) {
		case VSET: 	
			vstate=ISRC;
			break;
		case ISRC:
			vstate=ISNK;
			break;
		case ISNK:
			vstate=VSET;
			break;
		default:;
	}
	disp.updateGroupVII(vstate);
}

MENU MenuMain::handler(int e) {
	switch (e) {
		case 0: onEnter(); break;
		case 1: onCW(); break;
		case 2: onCCW(); break;
		case 3: onPB(); break;
		default:;
	}
	return MENU_MAIN;
}



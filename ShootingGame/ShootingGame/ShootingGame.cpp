// ShootingGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include"Menu.h"

int main(){
	Menu* menu = new Menu();
	menu->run();
	return 0;
}
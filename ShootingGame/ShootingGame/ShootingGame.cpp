// ShootingGame.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include"Menu.h"

int main() {
	system("mode con cols=200 lines=55"); // 화면의 첫 크기를 설정
	Menu* menu = new Menu();
	menu->run();
	return 0;
}
// ShootingGame.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include"Menu.h"

int main(){
	system("mode con cols=200 lines=55");
	Menu* menu = new Menu();
	menu->run();
	return 0;
}
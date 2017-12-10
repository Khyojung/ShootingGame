#include "Menu.h"
#include "Start.h"
#include "Ranking.h"
#include "Setting.h"

// ������, �Ҹ���
Menu::Menu() {
}
Menu::~Menu() {
}

// ������ getter, setter
int Menu::getMenuSelect() {
	return menuSelect;
}
void Menu::setMenuSelect(int newMenu) {
	menuSelect = newMenu;
}

// �Լ�
void Menu::run() { // Main���� ����Ǵ� �κ�
	int temp;
	Start* start = new Start();
	Ranking* ranking = new Ranking();
	Setting* setting = new Setting();
	Music* music = new Music();
	Sound* sound = new Sound();
	while(1) {
		system("cls");
		cout << "�޴��� �����ϼ���" <<endl;
		cout << "���ӽ���(1)	  ��ŷ(2)	  ����(3)	  ����(4)" <<endl;
		
		// ����ڷκ��� �޴������� �Է¹���
		cin >> temp;
		cout << endl;
		setMenuSelect(temp);

		// ���� ����
		if(getMenuSelect() == 1) {
			start->gameStart(ranking, sound);
		}
		// ��ŷ
		if(getMenuSelect() == 2) {
			ranking->rankPrint();
		}
		// ����
		if(getMenuSelect() == 3) {
			setting->print(ranking, music, sound);
		}
		// ����
		if(getMenuSelect() == 4) {
			cout<< "������ �����մϴ�." <<endl;
			system("pause");
			break;
		}
	}
}
#include "Menu.h"
#include "Start.h"
#include "Ranking.h"
#include "Setting.h"

// 생성자, 소멸자
Menu::Menu() {
}
Menu::~Menu() {
}

// 변수의 getter, setter
int Menu::getMenuSelect() {
	return menuSelect;
}
void Menu::setMenuSelect(int newMenu) {
	menuSelect = newMenu;
}

// 함수
void Menu::run() { // Main에서 실행되는 부분
	int temp;
	Start* start = new Start();
	Ranking* ranking = new Ranking();
	Setting* setting = new Setting();
	Music* music = new Music();
	Sound* sound = new Sound();
	while(1) {
		system("cls");
		cout << "메뉴를 선택하세요" <<endl;
		cout << "게임시작(1)	  랭킹(2)	  설정(3)	  종료(4)" <<endl;
		
		// 사용자로부터 메뉴선택을 입력받음
		cin >> temp;
		cout << endl;
		setMenuSelect(temp);

		// 게임 시작
		if(getMenuSelect() == 1) {
			start->gameStart(ranking, sound);
		}
		// 랭킹
		if(getMenuSelect() == 2) {
			ranking->rankPrint();
		}
		// 설정
		if(getMenuSelect() == 3) {
			setting->print(ranking, music, sound);
		}
		// 종료
		if(getMenuSelect() == 4) {
			cout<< "게임을 종료합니다." <<endl;
			system("pause");
			break;
		}
	}
}
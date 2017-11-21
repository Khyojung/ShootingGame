#include "Menu.h"
#include "Start.h"
#include "Ranking.h"
#include "Setting.h"

//생성자 소멸자
Menu::Menu(){

}
Menu::~Menu(){

}
//getter, setter
int Menu::getMenuSelect() {
	return menuSelect;
}
void Menu::setMenuSelect(int newMenu){
	menuSelect = newMenu;
}

//Main에서 실행되는 부분
void Menu::run(){
	int temp;
	while(1){
		cout << "메뉴를 선택하세요"<<endl;
		cout<<"게임시작(1)	  랭킹(2)	  설정(3)	  종료(4)"<<endl;
		
		//사용자로부터 메뉴선택을 입력받음

		cin >> temp;
		setMenuSelect(temp);

		//setMenuSelect(getch());

		//게임 시작
		if(getMenuSelect() == 1) {
			Start* start = new Start();
			start->gameStart();

		}
		//랭킹
		if(getMenuSelect() == 2) {
			Ranking* ranking = new Ranking();
			ranking->rankPrint();

		}
		//설정
		if(getMenuSelect() == 3) {
			Setting* setting = new Setting();
			setting->print();
		}

		//종료
		if(getMenuSelect() == 4) {
			cout<< "게임을 종료합니다." <<endl;
			system("pause");
			break;
		}
	}
}


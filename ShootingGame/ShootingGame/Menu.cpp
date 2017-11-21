#include "Menu.h"
#include "Start.h"
#include "Ranking.h"
#include "Setting.h"

//������ �Ҹ���
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

//Main���� ����Ǵ� �κ�
void Menu::run(){
	int temp;
	while(1){
		cout << "�޴��� �����ϼ���"<<endl;
		cout<<"���ӽ���(1)	  ��ŷ(2)	  ����(3)	  ����(4)"<<endl;
		
		//����ڷκ��� �޴������� �Է¹���

		cin >> temp;
		setMenuSelect(temp);

		//setMenuSelect(getch());

		//���� ����
		if(getMenuSelect() == 1) {
			Start* start = new Start();
			start->gameStart();

		}
		//��ŷ
		if(getMenuSelect() == 2) {
			Ranking* ranking = new Ranking();
			ranking->rankPrint();

		}
		//����
		if(getMenuSelect() == 3) {
			Setting* setting = new Setting();
			setting->print();
		}

		//����
		if(getMenuSelect() == 4) {
			cout<< "������ �����մϴ�." <<endl;
			system("pause");
			break;
		}
	}
}


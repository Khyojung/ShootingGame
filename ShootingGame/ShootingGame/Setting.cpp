#include"Setting.h"

Setting::Setting(){

}
Setting::~Setting(){

}
void Setting::musicSetting(){
	music.setMusicOn(!music.getMusicOn());
}
void Setting::soundSetting(){
	sound.setSoundOn(!sound.getSounOn());
}
//�޴����� setting���ý� ���
void Setting::print(){
	int selectTemp = 0;

	while(1) {
		cout << "������ �����ϼ���"<<endl;
		cout << "����:" << music.isMusicOn() << "(1)   ȿ����:" << sound.isSoundOn() << "(2)   ��ŷ�ʱ�ȭ(3)   ������(4)" <<endl;
		cin >> 	selectTemp;
		setSelectSetting(selectTemp);

		//����ڰ� ���� ����
		// ���� �Ѱ� ����
		if(getSelectSetting() == 1) {
			musicSetting();
		}

		// ȿ���� �Ѱ� ����
		else if(getSelectSetting() == 2) {
			soundSetting();
		}

		// ��ŷ �ʱ�ȭ
		else if(getSelectSetting() == 3) {
			rank.getDatabase().delRank();
		}

		// ������
		else if(getSelectSetting() == 4) {
			break;
		}
	}
}

//getter, setter
int Setting::getSelectSetting(){
	return selectSetting;
}
void Setting::setSelectSetting(int newSelect){
	selectSetting = newSelect;
}

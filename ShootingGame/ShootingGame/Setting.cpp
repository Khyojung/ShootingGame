#include"Setting.h"

// ������, �Ҹ���
Setting::Setting() {
}
Setting::~Setting() {
}

// ������ getter, setter
int Setting::getSelectSetting() {
	return selectSetting;
}
void Setting::setSelectSetting(int newSelect) {
	selectSetting = newSelect;
}

// �Լ�
void Setting::musicSetting() { // On�� ��� Off��, Off�� ��� On���� �ٲپ��ش�.
	music.setMusicOn(!music.getMusicOn());
}
void Setting::soundSetting() { // On�� ��� OFf��, Off�� ��� On���� �ٲپ��ش�.
	sound.setSoundOn(!sound.getSounOn());
}
void Setting::print(Ranking* rank) { // �޴����� setting���ý� ���
	int selectTemp = 0;

	while(1) {
		system("cls");
		cout << "������ �����ϼ���"<<endl;
		cout << "����:" << music.isMusicOn() << "(1)   ȿ����:" << sound.isSoundOn() << "(2)   ��ŷ�ʱ�ȭ(3)   ������(4)" <<endl;

		// ����ڰ� ���� ����
		cin >> selectTemp;
		setSelectSetting(selectTemp);

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
			rank->getDatabase()->delRank();
		}
		// ������
		else if(getSelectSetting() == 4) {
			break;
		}
	}
}
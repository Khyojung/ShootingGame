#include"Setting.h"

// 생성자, 소멸자
Setting::Setting() {
}
Setting::~Setting() {
}

// 변수의 getter, setter
int Setting::getSelectSetting() {
	return selectSetting;
}
void Setting::setSelectSetting(int newSelect) {
	selectSetting = newSelect;
}

// 함수
void Setting::musicSetting() { // On일 경우 Off로, Off일 경우 On으로 바꾸어준다.
	music.setMusicOn(!music.getMusicOn());
}
void Setting::soundSetting() { // On일 경우 OFf로, Off일 경우 On으로 바꾸어준다.
	sound.setSoundOn(!sound.getSounOn());
}
void Setting::print(Ranking* rank) { // 메뉴에서 setting선택시 출력
	int selectTemp = 0;

	while(1) {
		system("cls");
		cout << "설정을 선택하세요"<<endl;
		cout << "음악:" << music.isMusicOn() << "(1)   효과음:" << sound.isSoundOn() << "(2)   랭킹초기화(3)   나가기(4)" <<endl;

		// 사용자가 설정 선택
		cin >> selectTemp;
		setSelectSetting(selectTemp);

		// 음악 켜고 끄기
		if(getSelectSetting() == 1) {
			musicSetting();
		}
		// 효과음 켜고 끄기
		else if(getSelectSetting() == 2) {
			soundSetting();
		}
		// 랭킹 초기화
		else if(getSelectSetting() == 3) {
			rank->getDatabase()->delRank();
		}
		// 나가기
		else if(getSelectSetting() == 4) {
			break;
		}
	}
}
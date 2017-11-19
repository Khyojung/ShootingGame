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
//메뉴에서 setting선택시 출력
void Setting::print(){
	int selectTemp = 0;

	while(1) {
		cout << "설정을 선택하세요"<<endl;
		cout << "음악:" << music.isMusicOn() << "(1)   효과음:" << sound.isSoundOn() << "(2)   랭킹초기화(3)   나가기(4)" <<endl;
		cin >> 	selectTemp;
		setSelectSetting(selectTemp);

		//사용자가 설정 선택
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
			rank.getDatabase().delRank();
		}

		// 나가기
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

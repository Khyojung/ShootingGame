#include"Setting.h"

Setting::Setting(){

}
Setting::~Setting(){

}
void Setting::musicSetting(){

}
void Setting::soundSetting(){

}
//메뉴에서 setting선택시 출력
void Setting::print(){
	int selectTemp = 0;

	cout << "설정을 선택하세요"<<endl;
	cout << "음악(1)   효과음(2)" <<endl;
	cin >> 	selectTemp;
	setSelectSetting(selectTemp);

	//사용자가 설정 선택
	if(getSelectSetting() == 1){
		musicSetting();
	}
	else if(getSelectSetting() ==2){
		soundSetting();
	}
}

//getter, setter
int Setting::getSelectSetting(){
	return selectSetting;
}
void Setting::setSelectSetting(int newSelect){
	selectSetting = newSelect;
}

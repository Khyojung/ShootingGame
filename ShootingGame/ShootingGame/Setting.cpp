#include"Setting.h"

Setting::Setting(){

}
Setting::~Setting(){

}
void Setting::musicSetting(){

}
void Setting::soundSetting(){

}
//�޴����� setting���ý� ���
void Setting::print(){
	int selectTemp = 0;

	cout << "������ �����ϼ���"<<endl;
	cout << "����(1)   ȿ����(2)" <<endl;
	cin >> 	selectTemp;
	setSelectSetting(selectTemp);

	//����ڰ� ���� ����
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

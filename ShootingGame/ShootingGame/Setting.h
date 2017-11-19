#include<iostream>

using namespace std;

class Setting{
	
private:
	int selectSetting;
public:
	Setting();
	~Setting();
	void musicSetting();
	void soundSetting();
	void print();

	int getSelectSetting();
	void setSelectSetting(int);

};
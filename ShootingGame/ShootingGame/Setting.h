#include "Music.h"
#include "Sound.h"
#include "Ranking.h"
#include <iostream>

using namespace std;

class Setting{
	
private:
	int selectSetting;
	Music music;
	Sound sound;
	Ranking rank;
public:
	Setting();
	~Setting();
	void musicSetting();
	void soundSetting();
	void print();

	int getSelectSetting();
	void setSelectSetting(int);

};
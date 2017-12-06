#include "Music.h"
#include "Sound.h"
#include "Ranking.h"
#include <iostream>

using namespace std;

class Setting {	
private:
	int selectSetting;
	Music music;
	Sound sound;

public:
	Setting();
	~Setting();

	int getSelectSetting();
	void setSelectSetting(int);

	void musicSetting();
	void soundSetting();
	void print(Ranking*);
};
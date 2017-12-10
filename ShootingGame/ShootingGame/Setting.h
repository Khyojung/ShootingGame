#include "Music.h"
#include "Sound.h"
#include "Ranking.h"
#include <iostream>

using namespace std;

class Setting {	
private:
	int selectSetting;

public:
	Setting();
	~Setting();

	int getSelectSetting();
	void setSelectSetting(int);

	void musicSetting(Music*);
	void soundSetting(Sound*);
	void print(Ranking*, Music*, Sound*);
};
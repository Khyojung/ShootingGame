#pragma once
#include"Stage.h"

class Stage_inf : public Stage {
private:

public:
	Stage_inf();
	~Stage_inf();

	void showMap();
	int scoreCount();
	int timeFlow();
	int monsterCount();
};
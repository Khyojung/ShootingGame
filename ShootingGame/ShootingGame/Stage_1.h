#pragma once
#include"Stage.h"

class Stage_1 : public Stage {
private:

public:
	Stage_1();
	~Stage_1();

	void showMap();
	int scoreCount();
	int timeFlow();
	int monsterCount();
};
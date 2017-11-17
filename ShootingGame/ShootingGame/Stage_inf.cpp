#include<iostream>
#include"Stage.h"

using namespace std;
class Stage_inf : public Stage{
	
private:

public:
	Stage_inf();
	~Stage_inf();
	void showMap();
	int scoreCount();
	int timeFlow();
	int monsterCount();

};
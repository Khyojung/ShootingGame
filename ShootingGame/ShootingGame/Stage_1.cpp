#include<iostream>
#include"Stage.h"

using namespace std;
class Stage_1 : public Stage{
	
private:

public:
	Stage_1();
	~Stage_1();
	void showMap();
	int scoreCount();
	int timeFlow();
	int monsterCount();

};
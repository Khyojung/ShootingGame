#include<iostream>

using namespace std;
class Stage{
	
private:
	int map[100][300];
	int score;
	int time;
	int monsterCount;

public:
	Stage();
	~Stage();
	void showMap();
	int scoreCount();
	int timeFlow();
	int monsterCount();

};
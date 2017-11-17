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

	int getMap();
	void setMap(int[100][300]);
	int getScore();
	void setScore(int);
	int getTime();
	void setTime(int);
	int getMonsterCount();
	void setMonsterCount(int);

};
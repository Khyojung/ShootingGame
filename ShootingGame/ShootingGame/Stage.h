#include<iostream>

using namespace std;
class Stage{
	
private:
	int** map;
	int score;
	int time;
	int monsterCount;

public:
	Stage();
	~Stage();
	void showMap();
	int scoreCount();
	int timeFlow();

	int** getMap();
	void setMap(int**);
	int getScore();
	void setScore(int);
	int getTime();
	void setTime(int);
	int getMonsterCount();
	void setMonsterCount(int);

};
#pragma once
#include<iostream>

using namespace std;
class Stage{
	
private:
	int** map;
	int score;
	int time;
	int monsterCount;
	//Hero* hero;

public:
	Stage();
	~Stage();
	void showMap();
	int scoreCount();
	int timeFlow();

	int** getMap();
	void setMap(int**);
	void setMapXY(int,int,int);
	int getMapX();
	int getMapY();
	int getScore();
	void setScore(int);
	int getTime();
	void setTime(int);
	int getMonsterCount();
	void setMonsterCount(int);

};
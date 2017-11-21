#pragma once
#include <iostream>
#include "Hero.h"
#include <conio.h>
#include "screenBuffer.h"

using namespace std;

class Stage{
	
private:
	int** map;
	int score;
	int time;
	int monsterCount;
	screenBuffer buffer;

public:
	Stage();
	~Stage();
	void start();
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
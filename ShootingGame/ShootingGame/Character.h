#pragma once
#include<iostream>
#include<string>
#include"Stage.h"

using namespace std;

class Character{
	
private:
	Stage* stage;
	int hp;
	int speed;
	int damage;
	int time;
	int characterX;
	int characterY;

public:
	Character();
	~Character();
	void move();
	void attack();

	Stage* getStage();
	void setStage(Stage*);
	int getHp();
	void setHp(int);
	int getSpeed();
	void setSpeed(int);
	int getDamage();
	void setDamage(int);
	int getTime();
	void setTime(int);
	int getCharacterX();
	void setCharacterX(int);
	int getCharacterY();
	void setChracterY(int);

};
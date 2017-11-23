#pragma once
#include <iostream>

using namespace std;

class Character{
	
private:
	int hp;
	int speed;
	int damage;
	int time;
	int characterX;
	int characterY;
	char *shape;

public:
	Character();
	~Character();
	void move();
	void attack();

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
	void setCharacterY(int);
	char* getShape();
	void setShape(char*);

};
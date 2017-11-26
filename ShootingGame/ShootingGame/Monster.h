#pragma once

#include<iostream>
#include<string>
#include"Character.h"
#include "BulletDatabase.h"

using namespace std;

class Monster : public Character{
	
private:
	char* shape;
	int pattern;
	//BulletDatabase bulldata;

public:
	Monster();
	Monster(int newX, int newY);
	~Monster();

	void setPattern(int);
	int getPattern();
	void setShape(char*);
	char* getShape();

	void move();
	//void attack();
	static void createMonster();
};
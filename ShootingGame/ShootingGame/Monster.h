#pragma once

#include <iostream>
#include <string>
#include "Character.h"
#include "BulletDatabase.h"

using namespace std;

class Monster : public Character{
	
private:
	char* shape[3];
	//BulletDatabase bulldata;

public:
	Monster();
	Monster(int newX, int newY);
	~Monster();

	void setShape(char**);
	char** getShape();

	virtual void move() = 0;
	virtual bool attack() = 0;
};
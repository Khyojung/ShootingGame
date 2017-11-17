#pragma once

#include<iostream>
#include<string>
#include"Character.h"

using namespace std;

class Monster : public Character{
	
private:
	string shpae;
	int pattern;

public:
	Monster();
	~Monster();
	void move();
	void attack();

	void setPattern(int);
	int getPattern();
	void setShape(string);
	string getShape();
};
#pragma once

#include<iostream>
#include<string>
#include"Character.h"

using namespace std;

class Monster : public Character{
	
private:
	char **shape;
	int pattern;

public:
	Monster();
	~Monster();

	void setPattern(int);
	int getPattern();
	void setShape(char **);
	char ** getShape();
};
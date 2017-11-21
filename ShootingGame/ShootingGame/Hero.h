#pragma once
#include"Character.h"

using namespace std;

class Hero : public Character{
	
private:
	char* shape;
public:
	Hero();
	~Hero();
	void move(int keyboard);
	void attack();

	void setShape(char*);
	char* getShape();

};
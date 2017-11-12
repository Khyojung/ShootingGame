#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterMiddle : public Monster{
	
private:

public:
	MonsterMiddle();
	~MonsterMiddle();
	void move();
	void attack();

	void setPattern(int);
	int getPattern();
};
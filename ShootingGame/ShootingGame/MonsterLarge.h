#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterLarge : public Monster{
	
private:

public:
	MonsterLarge();
	~MonsterLarge();
	void move();
	void attack();

	void setPattern(int);
	int getPattern();
};
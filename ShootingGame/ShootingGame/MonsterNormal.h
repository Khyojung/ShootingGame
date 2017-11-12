#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterNormal : public Monster{
	
private:

public:
	MonsterNormal();
	~MonsterNormal();
	void move();
	void attack();

	void setPattern(int);
	int getPattern();
};
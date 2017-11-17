#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterBoss : public Monster{
	
private:

public:
	MonsterBoss();
	~MonsterBoss();
	void move();
	void attack();

	void setPattern(int);
	int getPattern();
};
#include<iostream>
#include"Character.h"
#include"Monster.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class MonsterBoss : public Monster{
	
private:
	bool right;
	clock_t begin;
public:
	void setRight(bool);
	bool getRight();


	MonsterBoss();
	MonsterBoss(int);
	~MonsterBoss();
	void move() override;
	bool attack() override;
};
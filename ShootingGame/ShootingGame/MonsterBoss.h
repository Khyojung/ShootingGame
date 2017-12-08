#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterBoss : public Monster{
	
private:
	bool right;

public:
	void setRight(bool);
	bool getRight();


	MonsterBoss();
	~MonsterBoss();
	void move() override;
	//void attack();
};
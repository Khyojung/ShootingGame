#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterLarge : public Monster{
	
private:
	bool right;
public:
	MonsterLarge();
	MonsterLarge(int, int);
	~MonsterLarge();

	void setRight(bool);
	bool getRight();
	void move() override;
	//void attack() override;
};
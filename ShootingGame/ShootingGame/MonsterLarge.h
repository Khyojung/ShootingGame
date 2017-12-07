#include <iostream>
#include "Character.h"
#include "Monster.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class MonsterLarge : public Monster{
	
private:
	bool right;
	clock_t begin;
public:
	MonsterLarge();
	MonsterLarge(int, int);
	~MonsterLarge();

	void setRight(bool);
	bool getRight();
	
	void move() override;
	bool attack() override;
};
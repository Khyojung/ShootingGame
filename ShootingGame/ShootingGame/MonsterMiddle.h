#include<iostream>
#include"Character.h"
#include"Monster.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class MonsterMiddle : public Monster{
	
private:

public:
	MonsterMiddle();
	MonsterMiddle(int, int, int);
	~MonsterMiddle();
	void move() override;
	bool attack() override;
};
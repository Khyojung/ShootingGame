#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterMiddle : public Monster{
	
private:

public:
	MonsterMiddle();
	MonsterMiddle(int, int);
	~MonsterMiddle();
	void move() override;
	bool attack() override;
};
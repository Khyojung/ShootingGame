#include<iostream>
#include"Character.h"
#include"Monster.h"

using namespace std;

class MonsterNormal : public Monster{
	
private:

public:
	MonsterNormal();
	MonsterNormal(int, int, int);
	~MonsterNormal();
	void move() override;
	bool attack() override;
};
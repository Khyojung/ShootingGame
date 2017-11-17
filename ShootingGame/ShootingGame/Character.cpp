#include<iostream>
#include<string>

using namespace std;

class Character{
	
private:
	int hp;
	int speed;
	int damage;
	int time;
	int characterX;
	int characterY;

public:
	Character();
	~Character();
	void move();
	void attack();

};
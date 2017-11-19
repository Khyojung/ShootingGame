#include <iostream>
#include "Character.h"
#include "BulletDatabase.h"

using namespace std;

class Bullet : public Character{
	
private:
	int patternX;
	int patternY;
	string shpae;

public:
	Bullet();
	~Bullet();
	void move();
	void attack();

	void setPattern(int);
	int getPattern();

};
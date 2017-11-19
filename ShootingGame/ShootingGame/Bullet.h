
#include<iostream>
#include"Character.h"
#include"BulletDatabase.h"

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

	void setPatternX(int);
	int getPatternX();
	void setPatternY(int);
	int getPatternY();
	void setShape(string);
	string getShape();

};
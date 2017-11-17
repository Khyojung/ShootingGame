#include<iostream>
#include"Character.h"

using namespace std;
class Hero : public Character{
	
private:
	string shpae;

public:
	Hero();
	~Hero();
	void move();
	void attack();

	void setShape(string);
	string getShape();

};
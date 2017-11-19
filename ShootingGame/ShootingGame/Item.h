#include<iostream>
#include"Character.h"

using namespace std;
class Item{
	
private:
	int itemX;
	int itemY;
	string shape;
public:
	Item();
	~Item();
	void property(Character ch);
	int scoreCount();
	int timeFlow();
	int monsterCount();

	int getItemX();
	void setItemX(int);
	int getItemY();
	void setItemY(int);
	string getShape();
	void setShape(string);
};
#include<iostream>
#include"Item.h"

using namespace std;
class ItemSpeedUp : public Item{
	
private:

public:
	ItemSpeedUp();
	~ItemSpeedUp();
	void property(Character ch);
	void move();
	void eaten();

};
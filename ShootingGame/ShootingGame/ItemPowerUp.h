#include<iostream>
#include"Item.h"

using namespace std;
class ItemPowerUp : public Item{
	
private:

public:
	ItemPowerUp();
	~ItemPowerUp();
	void property(Character ch);
	void move();
	void eaten();

};
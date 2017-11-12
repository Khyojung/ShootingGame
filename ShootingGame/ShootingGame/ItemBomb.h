#include<iostream>
#include"Item.h"

using namespace std;
class ItemBomb : public Item{
	
private:

public:
	ItemBomb();
	~ItemBomb();
	void property(Character ch);
	void move();
	void eaten();

};
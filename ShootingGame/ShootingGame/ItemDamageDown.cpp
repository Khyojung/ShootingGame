#include<iostream>
#include"Item.h"

using namespace std;
class ItemDamageDown : public Item{
	
private:

public:
	ItemDamageDown();
	~ItemDamageDown();
	void property(Character ch);
	void move();
	void eaten();

};
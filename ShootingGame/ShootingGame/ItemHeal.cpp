#include<iostream>
#include"Item.h"

using namespace std;
class ItemHeal : public Item{
	
private:

public:
	ItemHeal();
	~ItemHeal();
	void property(Character ch);
	void move();
	void eaten();

};
#ifndef __ITEMBOMB_H
#define __ITEMBOMB_H
#include<iostream>
#include"Item.h"

using namespace std;
class ItemBomb : public Item{
	
private:

public:
	ItemBomb();
	~ItemBomb();


	virtual int itemFunction(Hero*);


};
#endif
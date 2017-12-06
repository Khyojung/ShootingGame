#pragma once
#include<iostream>
#include"Item.h"

using namespace std;
class ItemDamageDown : public Item{
	
private:

public:
	ItemDamageDown();
	~ItemDamageDown();
	virtual int itemFunction(Hero*);

};
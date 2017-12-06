#pragma once
#include<iostream>
#include"Item.h"

using namespace std;
class ItemHeal : public Item{
	
private:

public:
	ItemHeal();
	~ItemHeal();

	virtual int itemFunction(Hero*);
};
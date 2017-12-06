#pragma once
#include<iostream>
#include"Item.h"

using namespace std;
class ItemPowerUp : public Item{
	
private:

public:
	ItemPowerUp();
	~ItemPowerUp();

	virtual void itemFunction(Hero*);

};
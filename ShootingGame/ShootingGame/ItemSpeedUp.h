#pragma once
#include<iostream>
#include"Item.h"


using namespace std;
class ItemSpeedUp : public Item{
	
private:

public:
	ItemSpeedUp();
	~ItemSpeedUp();

	virtual int itemFunction(Hero*);

};
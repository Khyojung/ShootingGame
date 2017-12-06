#pragma once
#include <map>
#include <iostream>
#include <algorithm>

#include "screenBuffer.h"
#include "Item.h"
#include "Hero.h"

using namespace std;


class ItemDatabase{
private:
	map <int, Item*> item;
	int itemCount;

public:
	ItemDatabase();
	~ItemDatabase();

	bool addItem(int, Item*);
	void delItem(int);
	void printItem(screenBuffer);
	bool moveItem();
	int whenEatenbyHero(Hero* );
	void timeFlow();
};
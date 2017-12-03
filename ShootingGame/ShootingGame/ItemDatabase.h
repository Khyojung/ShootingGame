#pragma once
#include <map>
#include <iostream>
#include <algorithm>
#include "screenBuffer.h"
#include "Item.h"

using namespace std;

template <class T>
class ItemDatabase{
private:
	multimap <int, T*> item;

public:
	ItemDatabase();
	~ItemDatabase();

	void addItem(int, T*);
	void delItem(int);
	void printItem(screenBuffer*);
	bool moveItem();
};
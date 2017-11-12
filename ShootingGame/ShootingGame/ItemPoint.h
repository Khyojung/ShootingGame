#include<iostream>
#include"Item.h"

using namespace std;
class ItemPoint : public Item{
	
private:

public:
	ItemPoint();
	~ItemPoint();
	void property(Character ch);
	void move();
	void eaten();

};
#pragma once
#include"ItemBomb.h"
#include"ItemDamageDown.h"
#include"ItemHeal.h"
#include"ItemPoint.h"
#include"ItemPowerUp.h"
#include"ItemSpeedUp.h"

#include"ItemDatabase.h"

using namespace std;

class ItemHouse : public Character{

private:
	ItemDatabase* itemDatabase;
	Item* item;
	int itemCount;

public:
	ItemHouse();
	~ItemHouse();

	void setItemDatabase(ItemDatabase*);
	ItemDatabase* getItemDatabase();
	void setItemCount(int);
	int getItemCount();
	void newItem();
	void showItem();


};
#pragma once
#include"ItemBomb.h"
#include"ItemDamageDown.h"
#include"ItemHeal.h"
#include"ItemPoint.h"
#include"ItemPowerUp.h"
#include"ItemSpeedUp.h"

#include"ItemDatabase.h"

using namespace std;
template <class T>
class ItemHouse : public Character{

private:
	ItemDatabase<T> itemDatabase;
	Item* item;
	int itemCount;
public:
	ItemHouse();
	~ItemHouse();

	void setItemDatabase(ItemDatabase<T>);
	ItemDatabase<T> getItemDatabase();
	void setItemCount(int);
	int getItemCount();
	void newItem();
	void showItem(screenBuffer* buffer);
};
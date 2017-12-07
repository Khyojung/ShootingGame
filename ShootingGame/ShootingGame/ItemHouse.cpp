#include "ItemHouse.h"
#include "ItemDatabase.h"

using namespace std;


ItemHouse<Item>::ItemHouse(){
	setItemCount(0);
}
ItemHouse<Item>::~ItemHouse(){

}
void ItemHouse<Item>::setItemDatabase(ItemDatabase<Item> newItemDatabase){
	itemDatabase = newItemDatabase;
}
ItemDatabase<Item> ItemHouse<Item>::getItemDatabase(){
	return itemDatabase;
}


template<>
void ItemHouse<Item>::setItemCount(int newItemCount) {
	itemCount = newItemCount;
}
int ItemHouse<Item>::getItemCount() {
	return itemCount;
}

void ItemHouse<Item>::newItem(){

	int temp = 0;
	srand((unsigned int)time(NULL));
	temp = rand()%6;
	switch(temp){
	case 0:
		item = new ItemBomb();
		break;
	case 1:
		item = new ItemDamageDown();
		break;

	case 2:
		item = new ItemHeal();
		break;
	case 3:
		item = new ItemPoint();
		break;
	case 4:
		item = new ItemSpeedUp();
		break;
	case 5:
		item = new ItemPowerUp();
		break;
	default:
		break;
	}
	itemDatabase.addItem(getItemCount(), item);
	setItemCount(getItemCount()+1);

}
void ItemHouse<Item>::showItem(screenBuffer* buffer){
	int temp = 0;
	srand((unsigned int)time(NULL));
	temp = rand()%100;
	if(temp <= 20){
		newItem();
	
	}
	itemDatabase.printItem(buffer);
}
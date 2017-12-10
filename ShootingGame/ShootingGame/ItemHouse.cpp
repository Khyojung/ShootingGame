#include "ItemHouse.h"
#include "ItemDatabase.h"

using namespace std;

ItemHouse::ItemHouse(){
	itemDatabase = new ItemDatabase();
	setItemCount(0);

}
ItemHouse::~ItemHouse(){
}
void ItemHouse::setItemDatabase(ItemDatabase* newItemDatabase){
	itemDatabase = newItemDatabase;
}
ItemDatabase* ItemHouse::getItemDatabase(){
	return itemDatabase;
}

void ItemHouse::setItemCount(int newItemCount) {
	itemCount = newItemCount;
}
int ItemHouse::getItemCount() {
	return itemCount;
}

void ItemHouse::newItem(){

	int temp = 0;
	srand((unsigned int)time(NULL));
	temp = rand()*rand()%10;
	switch(temp){
	case 0:
		item = new ItemBomb();
		break;
	case 1 :
	case 6 :
		item = new ItemDamageDown();
		break;
	case 2:
		item = new ItemHeal();
		break;
	case 3:
	case 7 :
	case 8 :
		item = new ItemPoint();
		break;
	case 4:
		item = new ItemSpeedUp();
		break;
	case 5:
	case 9:
		item = new ItemPowerUp();
		break;
	default:
		break;
	}

	if(itemDatabase->addItem(getItemCount(), item))
		setItemCount(getItemCount()+1);

}
void ItemHouse::showItem(){
	int temp = 0;
	srand((unsigned int)time(NULL));
	temp = rand();
	if((temp % 2 == 1) ){
		newItem();
	}
}

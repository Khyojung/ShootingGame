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
	temp = rand()%6;
	/*switch(temp){
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
	}*/
		item = new ItemHeal();

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
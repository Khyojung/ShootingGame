#include"ItemBomb.h"

ItemBomb::ItemBomb(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);


	setShape("¡Ý");
}
void ItemBomb::itemFunction(Hero* hero){
	hero->setBombCount(hero->getBombCount()+1);
}

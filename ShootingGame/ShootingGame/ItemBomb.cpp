#include"ItemBomb.h"

ItemBomb::ItemBomb(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);


	setShape("��");
}
void ItemBomb::itemFunction(Hero* hero){
	hero->setBombCount(hero->getBombCount()+1);
}

#include"ItemDamageDown.h"

ItemDamageDown::ItemDamageDown(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("��");
}

void ItemDamageDown::itemFunction(Hero* hero){
	hero->setDamage(hero->getDamage()-1);
}

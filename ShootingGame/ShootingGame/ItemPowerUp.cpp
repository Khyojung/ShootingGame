#include"ItemPowerUp.h"

ItemPowerUp::ItemPowerUp(){
	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("ก่");
}

void ItemPowerUp::itemFunction(Hero* hero){
	hero->setDamage(hero->getDamage()+1);
}

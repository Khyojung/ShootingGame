#include"ItemHeal.h"

ItemHeal::ItemHeal(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("��");
}

void ItemHeal::itemFunction(Hero* hero){
	hero->setHp(hero->getHp()+1);
}

#include"ItemHeal.h"

ItemHeal::ItemHeal(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("¢¾");
}

int ItemHeal::itemFunction(Hero* hero){
	if(hero->getHp() < 5)
		hero->setHp(hero->getHp()+1);

		return getScore();
}

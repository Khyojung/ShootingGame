#include"ItemPowerUp.h"

ItemPowerUp::ItemPowerUp(){
	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("��");
}

int ItemPowerUp::itemFunction(Hero* hero){
	if(hero->getDamage() < 5)
		hero->setDamage(hero->getDamage()+1);

		return getScore();
}

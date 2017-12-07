#include"ItemBomb.h"

ItemBomb::ItemBomb(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);


	setShape("��");
}
int ItemBomb::itemFunction(Hero* hero){
	if(hero->getBombCount() <= 5)
		hero->setBombCount(hero->getBombCount()+1);

	return getScore();
}

#include"ItemPoint.h"

ItemPoint::ItemPoint(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("��");
}

void ItemPoint::itemFunction(Hero* hero){
	hero->setBombCount(hero->getBombCount()+1);
}

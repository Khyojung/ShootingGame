#include"ItemSpeedUp.h"

ItemSpeedUp::ItemSpeedUp(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("��");
}
void ItemSpeedUp::itemFunction(Hero* hero){
	hero->setBombCount(hero->getBombCount()+1);
}

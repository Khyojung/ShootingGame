#include"ItemPowerUp.h"

ItemPowerUp::ItemPowerUp(){
	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);



	setShape("ii");
}

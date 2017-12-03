#include"ItemBomb.h"

ItemBomb::ItemBomb(){

	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);


	setShape("¤±");
}

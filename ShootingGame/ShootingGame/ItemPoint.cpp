#include"ItemPoint.h"

ItemPoint::ItemPoint(){
	setCharacterY(itemRandomY());
	setCharacterX(itemRandomX());
	setTime(3);
	setShape("��");
}
ItemPoint::~ItemPoint() {
}

int ItemPoint::itemFunction(Hero* hero){
	return 5*getScore();
}

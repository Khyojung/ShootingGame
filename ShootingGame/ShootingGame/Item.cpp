#include "Item.h"

using namespace std;

//������ �Ҹ���
Item::Item(){

}
Item::~Item(){

}
int Item::itemRandomX(){

	srand((unsigned int)time(NULL));
	randomx = (rand()*rand())%20;
	return randomx;
}
int Item::itemRandomY(){

	srand((unsigned int)time(NULL));
	randomy = (rand()*rand())%30+10;
	return randomy;
}
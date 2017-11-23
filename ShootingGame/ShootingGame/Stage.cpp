#pragma once
#include"Stage.h"

//생성자 소멸자
Stage::Stage(){
	int** newMap;
	newMap = (int**)malloc(sizeof(int*)*50);
	for(int i = 0; i < 50; i++) {
		newMap[i] = (int*)malloc(sizeof(int)*20);
		for(int j = 0; j < 20; j++) {
			newMap[i][j] = 0;
		}
	}
	setMap(newMap);
}
Stage::~Stage(){

}

void Stage::start() {
	hero = new Hero();
	setMapXY(hero->getCharacterX(), hero->getCharacterY(), -1);
	buffer.CreateBuffer();
	showMap();
	while(1) {
		if(hero->getTime() > 0)
			hero->setTime(hero->getTime()-1);
		if(hero->getHeroBullet()->moveBullet()) {
			showMap();
		}
		if(kbhit()) {;
			int key = getch();
			if(key == 224 || key == 0) {
				key = getch();
				setMapXY(hero->getCharacterX(), hero->getCharacterY(), 0);
				hero->move(key);
				if(getMap()[hero->getCharacterY()][hero->getCharacterX()] != 0) {
					// 충돌!!!
				}
				else {
					setMapXY(hero->getCharacterX(), hero->getCharacterY(), -1);
				}
				showMap();
			}
			else if(key == 32 && hero->getTime() <= 0) { // 스페이스바 눌리면
				hero->setTime(10);
				hero->attack();
				showMap();
			}
		}
	}
	buffer.Release();
}
void Stage::showMap() {
	int i, j;
	buffer.BufferClear();
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 0, "■");
	}
	for(i = 0; i < 50; i++) {
		buffer.BufferWrite(0, i+1, "■");
		for(j = 0; j < 20; j++) {
		}
		buffer.BufferWrite((j+1)*2, i+1, "■");
	}
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 51, "■");
	}
	multimap<int, Bullet*>::iterator iter;
	hero->getHeroBullet()->printBullet(buffer);
	buffer.BufferWrite(hero->getCharacterX()*2+2, hero->getCharacterY()+1, hero->getShape());
	buffer.Flipping();
}

//getter, setter
int** Stage::getMap(){
	return map;
}
void Stage::setMap(int** newMap){
	map = newMap;
}
void Stage::setMapXY(int X, int Y, int value) {
	map[Y][X] = value;
}
int Stage::getMapX() {
	return sizeof(*getMap())/sizeof(int);
}
int Stage::getMapY() {
	return sizeof(getMap())/sizeof(*getMap());
}
int Stage::getScore(){
	return score;
}
void Stage::setScore(int newScore){
	score = newScore;
}
int Stage::getTime(){
	return time;
}
void Stage::setTime(int newTime){
	time = newTime;
}
int Stage::getMonsterCount(){
	return monsterCount;
}
void Stage::setMonsterCount(int newMonsterCount){
	monsterCount = newMonsterCount;
}

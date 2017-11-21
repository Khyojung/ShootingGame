#pragma once
#include"Stage.h"

//积己磊 家戈磊
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
	int i,j;
	Hero hero;
	setMapXY(hero.getCharacterX(), hero.getCharacterY(), -1);
	buffer.CreateBuffer();
	buffer.BufferClear();
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 0, "♂");
	}
	for(i = 0; i < 50; i++) {
		buffer.BufferWrite(0, i+1, "♂");
		for(j = 0; j < 20; j++) {
			if(getMap()[i][j] == 0) {
				buffer.BufferWrite((j+1)*2, i+1, "  ");
			}
			if(getMap()[i][j] == -1) {
				buffer.BufferWrite((j+1)*2, i+1, hero.getShape());
			}
		}
		buffer.BufferWrite((j+1)*2, i+1, "♂");
	}
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 51, "♂");
	}
	buffer.Flipping();
	while(1) {
		if(hero.getTime() > 0)
			hero.setTime(hero.getTime()-1);
		if(kbhit() && hero.getTime() == 0) {;
			int key = getch();
			if(key == 224 || key == 0) {
				key = getch();
				fflush(stdin);
				setMapXY(hero.getCharacterX(), hero.getCharacterY(), 0);
				hero.move(key);
				if(getMap()[hero.getCharacterY()][hero.getCharacterX()] != 0) {
					// 面倒!!!
				}
				else {
					setMapXY(hero.getCharacterX(), hero.getCharacterY(), -1);
				}
				hero.setTime(1000);
				//buffer.CreateBuffer();
				buffer.BufferClear();
				for(i = 0; i < 22; i++) {
					buffer.BufferWrite(i*2, 0, "♂");
				}
				for(i = 0; i < 50; i++) {
					buffer.BufferWrite(0, i+1, "♂");
					for(j = 0; j < 20; j++) {
						if(getMap()[i][j] == 0) {
							buffer.BufferWrite((j+1)*2, i+1, "  ");
						}
						if(getMap()[i][j] == -1) {
							buffer.BufferWrite((j+1)*2, i+1, hero.getShape());
						}
					}
					buffer.BufferWrite((j+1)*2, i+1, "♂");
				}
				for(i = 0; i < 22; i++) {
					buffer.BufferWrite(i*2, 51, "♂");
				}
				buffer.Flipping();
			}
		}
	}
	buffer.Release();
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

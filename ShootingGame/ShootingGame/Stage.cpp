#include<iostream>
#include"Stage.h"

//持失切 社瑚切
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

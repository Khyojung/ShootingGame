#include<iostream>
#include"Stage.h"

//������ �Ҹ���
Stage::Stage(){

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

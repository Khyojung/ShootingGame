#include<iostream>
#include"Stage.h"

/*using namespace std;
class Stage{
	
private:
	int map[100][300];
	int score;
	int time;
	int monsterCount;

public:
	Stage();
	~Stage();
	void showMap();
	int scoreCount();
	int timeFlow();
	int monsterCount();

	int getMap();
	void setMap(int[100][300]);
	int getScore();
	void setScore(int);
	int getTime();
	void setTime(int);
	int getMonsterCount();
	void setMonsterCount(int);

};*/

Stage::Stage(){

}
Stage::~Stage(){

}

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

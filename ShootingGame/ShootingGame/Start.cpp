#include<iostream>
#include"Start.h"
#include"Stage_1.h"
#include"Stage_2.h"
#include"Stage_3.h"
#include"Stage_inf.h"

Start::Start(){

}
Start::~Start(){

}
//getter, setter

int Start::getLevel(){
	return level;
}
void Start::setLevel(int newLevel){
	level = newLevel;
}

void Start::gameStart(){
	int temp;
	
	cout << "모드를 선택하세요"<<endl;
	cout << "easy모드(1)    normal모드(2)    hard모드(3)    무한모드(4)"<<endl;
	cin>>temp;
	setLevel(temp);
	if(getLevel() == 1){
		Stage_1* stage_1 = new Stage_1();
		stage_1->start();
	}
	else if(getLevel() == 2){
		Stage_2* stage_2 = new Stage_2();
	}
	else if(getLevel() == 3){
		Stage_3* stage_3 = new Stage_3();
	}
	else if(getLevel() == 4){
		Stage_inf* stage_inf = new Stage_inf();
	}
}
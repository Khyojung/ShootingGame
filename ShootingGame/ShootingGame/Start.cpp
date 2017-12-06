#include"Start.h"
#include"Stage_1.h"
#include"Stage_2.h"
#include"Stage_3.h"
#include"Stage_inf.h"

// 생성자, 소멸자
Start::Start() {
}
Start::~Start() {
}

// 변수의 getter, setter
int Start::getLevel() {
	return level;
}
void Start::setLevel(int newLevel) {
	level = newLevel;
}

// 함수
void Start::gameStart(Ranking* rank) { // 게임의 시작
	int temp;
	cout << "모드를 선택하세요"<<endl;
	cout << "easy모드(1)    normal모드(2)    hard모드(3)    무한모드(4)"<<endl;

	// 사용자로부터 난이도를 입력받음
	cin>>temp;
	setLevel(temp);

	// 1단계
	if(getLevel() == 1){
		Stage_1* stage_1 = new Stage_1();
		stage_1->start(rank);
	}
	// 2단계
	else if(getLevel() == 2){
		Stage_2* stage_2 = new Stage_2();
		stage_2->start(rank);
	}
	// 3단계
	else if(getLevel() == 3){
		Stage_3* stage_3 = new Stage_3();
		stage_3->start(rank);
	}
	// 무한
	else if(getLevel() == 4){
		Stage_inf* stage_inf = new Stage_inf();
		stage_inf->start(rank);
	}
}
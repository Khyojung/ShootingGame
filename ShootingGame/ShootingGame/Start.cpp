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
void Start::gameStart(Ranking* rank, Sound* sound) { // 게임의 시작
	int temp;
	int monsterPoint = 0;
	int timePoint = 0;

	cout << "모드를 선택하세요"<<endl;
	cout << "easy모드(1)    normal모드(2)    hard모드(3)    무한모드(4)"<<endl;

	// 사용자로부터 난이도를 입력받음
	cin>>temp;
	setLevel(temp);

	// 1단계
	if(getLevel() == 1){
		Stage_1* stage_1 = new Stage_1();
		stage_1->run(&monsterPoint, &timePoint, sound);
	}
	// 2단계
	else if(getLevel() == 2){
		Stage_2* stage_2 = new Stage_2();
		stage_2->run(&monsterPoint, &timePoint, sound);
	}
	// 3단계
	else if(getLevel() == 3){
		Stage_3* stage_3 = new Stage_3();
		stage_3->run(&monsterPoint, &timePoint, sound);
	}
	// 무한
	else if(getLevel() == 4){
		Stage_inf* stage_inf = new Stage_inf();
		stage_inf->run(&monsterPoint, &timePoint, sound);
	}

	char name[40];
	//cout << "사망!!!" << endl;
	cout << "파괴점수 : " << monsterPoint << "    시간점수 : " << timePoint << endl;
	cout << "당신의 영문 이름을 입력해 주세요 : ";
	scanf("%s",name);
	rank->getDatabase()->addRank(monsterPoint + timePoint, name);
	system("cls");
}
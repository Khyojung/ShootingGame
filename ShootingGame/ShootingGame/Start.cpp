#include"Start.h"
#include"Stage_1.h"
#include"Stage_2.h"
#include"Stage_3.h"
#include"Stage_inf.h"

// ������, �Ҹ���
Start::Start() {
}
Start::~Start() {
}

// ������ getter, setter
int Start::getLevel() {
	return level;
}
void Start::setLevel(int newLevel) {
	level = newLevel;
}

// �Լ�
void Start::gameStart(Ranking* rank, Sound* sound) { // ������ ����
	int temp;
	int monsterPoint = 0;
	int timePoint = 0;

	cout << "��带 �����ϼ���"<<endl;
	cout << "easy���(1)    normal���(2)    hard���(3)    ���Ѹ��(4)"<<endl;

	// ����ڷκ��� ���̵��� �Է¹���
	cin>>temp;
	setLevel(temp);

	// 1�ܰ�
	if(getLevel() == 1){
		Stage_1* stage_1 = new Stage_1();
		stage_1->run(&monsterPoint, &timePoint, sound);
	}
	// 2�ܰ�
	else if(getLevel() == 2){
		Stage_2* stage_2 = new Stage_2();
		stage_2->run(&monsterPoint, &timePoint, sound);
	}
	// 3�ܰ�
	else if(getLevel() == 3){
		Stage_3* stage_3 = new Stage_3();
		stage_3->run(&monsterPoint, &timePoint, sound);
	}
	// ����
	else if(getLevel() == 4){
		Stage_inf* stage_inf = new Stage_inf();
		stage_inf->run(&monsterPoint, &timePoint, sound);
	}

	char name[40];
	//cout << "���!!!" << endl;
	cout << "�ı����� : " << monsterPoint << "    �ð����� : " << timePoint << endl;
	cout << "����� ���� �̸��� �Է��� �ּ��� : ";
	scanf("%s",name);
	rank->getDatabase()->addRank(monsterPoint + timePoint, name);
	system("cls");
}
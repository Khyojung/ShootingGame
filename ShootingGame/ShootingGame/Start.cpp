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
void Start::gameStart(Ranking* rank) { // ������ ����
	int temp;
	cout << "��带 �����ϼ���"<<endl;
	cout << "easy���(1)    normal���(2)    hard���(3)    ���Ѹ��(4)"<<endl;

	// ����ڷκ��� ���̵��� �Է¹���
	cin>>temp;
	setLevel(temp);

	// 1�ܰ�
	if(getLevel() == 1){
		Stage_1* stage_1 = new Stage_1();
		stage_1->start(rank);
	}
	// 2�ܰ�
	else if(getLevel() == 2){
		Stage_2* stage_2 = new Stage_2();
		stage_2->start(rank);
	}
	// 3�ܰ�
	else if(getLevel() == 3){
		Stage_3* stage_3 = new Stage_3();
		stage_3->start(rank);
	}
	// ����
	else if(getLevel() == 4){
		Stage_inf* stage_inf = new Stage_inf();
		stage_inf->start(rank);
	}
}
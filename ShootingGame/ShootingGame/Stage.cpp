#include"Stage.h"

// ������, �Ҹ���
Stage::Stage() { // �� �ʱ�ȭ, �迭�� �ʱ�ȭ �ϴ� �κ��� ������, ������ ��ü�� �����ϱ� ������ ���� �迭�� �ʿ䰡 ����.
}
Stage::~Stage(){
}

// ������ getter, setter
// ������ �迭 ���� ���ͼ��͸� ������. ������ ������ �迭 ���� �ʿ䰡 ���� ������ ������ �迭 ���� ������.
int Stage::getScore() {
	return score;
}
void Stage::setScore(int newScore) {
	score = newScore;
}
int Stage::getTime() {
	return time;
}
void Stage::setTime(int newTime) {
	time = newTime;
}
int Stage::getMonsterCount() {
	return monsterCount;
}
void Stage::setMonsterCount(int newMonsterCount) {
	monsterCount = newMonsterCount;
}

// �Լ�
void Stage::start() { //������ �帧
	hero = new Hero(); // ���� ����

	// ȭ�� ���� ����
	buffer.CreateBuffer();

	// ȭ�� ���
	showMap();
	while(hero->getHp() > 0) { // �ϴ��� ������ �ױ� ������ ����
		if(hero->getTime() > 0) { // ������ ���� ���ð� ����
			hero->setTime(hero->getTime()-1);
		}
		if(hero->getHeroBullet()->moveBullet()) { // �Ѿ��� ������ �� �������� ���� �� ȭ�� ��ȯ
			showMap(); // ȭ�� ��ȯ
		}
		if(kbhit()) { // Ű���� �Է��� ���� ���
			int key = getch(); // Ű������ Ű�� �Է� �޴´�
			if(key == 224 || key == 0) { // ����Ű�ΰ� �˻�
				key = getch(); // Ű������ Ű�� �ѹ��� �޴´�
				hero->move(key);
				// ĳ���Ͱ� ���������Ƿ� ���⼭�� �浹 �˻縦 �ؾ��ұ�? �ƴϸ� �Ѿ˿������� �浹�� �˻��ϸ� �ɱ�? �̹� �Ѿ��� �����ϴ� ������ �̵��� ��� ��� �ɰ��ΰ�???
				// �׷��� �浹�� �˻��ϴ� �κ��� Stage���� �Ѱ��ϴ°� ���ұ�, �ƴϸ� ������ ��ü�� �浹�� ������ �˻��ϴ°� ���ұ�?
				// �ᱹ���� ���μ��ΰ� ������ ���� ���غ����ϴ� ������ �߻��Ѵ�.
				showMap();
			}
			else if(key == 32 && hero->getTime() <= 0) { // �����̽��� ������
				hero->setTime(10); // ���� ���ð� �ʱ�ȭ
				hero->attack(); // �Ѿ� ����
				showMap(); // ȭ�� ��ȯ
			}
		}
	}
	buffer.Release(); // ȭ�� ���۸� ��������
}
void Stage::showMap() { // ȭ�� ������ִ� �κ�
	// Ʋ ���
	int i, j;
	buffer.BufferClear();
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 0, "��");
	}
	for(i = 0; i < 50; i++) {
		buffer.BufferWrite(0, i+1, "��");
		for(j = 0; j < 20; j++) {
		}
		buffer.BufferWrite((j+1)*2, i+1, "��");
	}
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 51, "��");
	}

	// �Ѿ� ���
	multimap<int, Bullet*>::iterator iter;
	hero->getHeroBullet()->printBullet(buffer);

	// ���� ���
	buffer.BufferWrite(hero->getCharacterX()*2+2, hero->getCharacterY()+1, hero->getShape());

	// ȭ�� ��ȯ
	buffer.Flipping();
}
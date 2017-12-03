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
	return atime;
}
void Stage::setTime(int newTime) {
	atime = newTime;
}

// �Լ�
void Stage::start() { //������ �帧
	begin = clock();
	hero = new Hero(); // ���� ����
	monsterDatabase = new MonsterDatabase();
	score = 0;
	gameRunSpead = 20;
	int count = 0;

	// ȭ�� ���� ����
	buffer.CreateBuffer();

	// ȭ�� ���
	showMap();
	while(hero->getHp() > 0) { // �ϴ��� ������ �ױ� ������ ����
		if(hero->getTime() > 0) { // ������ ���� ���ð� ����
			hero->setTime(hero->getTime()-1);
		}

		hero->getHeroBullet()->moveBullet(); // �Ѿ��� ������ �� �������� ���� �� ȭ�� ��ȯ

		//���� ���� �� �̵�
		if(count % gameRunSpead == 0){
			//���� ���̵��� ���� �ӵ��� �޶�����.
			monsterDatabase->moveMonster();
			if(count % (gameRunSpead*2) == 0){
				//���� ���̵��� ���� ���� ���� �ӵ��� �ٸ���.
				//�����̴� ���� 1/2�� ���� �Ǵ� �ӵ��� �����ȴ�.
				srand((unsigned int)time(NULL));
				monsterDatabase->randomCreateMonster();
			}
		}
		count++;
		showMap();

		score = score + monsterDatabase->whenCrashWithHero(hero);
		score = score + monsterDatabase->whenCrashWithBullet(hero);

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
			if(key == 98 && hero->getBombCount() > 0) { // b�� ������
				score = score + monsterDatabase->whenHeroUseBomb(hero->getBombDamage()); // ���� �����ͺ��̽��� ������ ��ź ���ݷ� ��ŭ�� ���ظ� ��
				hero->setBombCount(hero->getBombCount() - 1); // ��ź ���� ����
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

	//Monster ���
	monsterDatabase->print(buffer);
	
	// ��� �⺻ ��ġ ����
	int printX = 46;
	int printY = 50;

	// �ð� ���
	end = clock();
	char convertString[40];
	itoa((end-begin)/CLOCKS_PER_SEC * 100, convertString, 10);
	buffer.BufferWrite(printX, printY, "Time : ");
	buffer.BufferWrite(printX+7, printY, convertString);

	// ���� ���
	itoa(score * 100, convertString, 10);
	buffer.BufferWrite(printX, printY-1, "Score : ");
	buffer.BufferWrite(printX+8, printY-1, convertString);

	// ü�� ���
	buffer.BufferWrite(printX, printY-2, "HP : ");
	for(int i = 0; i < hero->getHp(); i++) {
		buffer.BufferWrite(printX+5+(i*2), printY-2, "��");
	}

	// ��ź ���� ���
	buffer.BufferWrite(printX, printY-3, "BOMB : ");
	for(int i = 0; i < hero->getBombCount(); i++) {
		buffer.BufferWrite(printX+7+(i*2), printY-3, "��");
	}

	// ȭ�� ��ȯ
	buffer.Flipping();
}
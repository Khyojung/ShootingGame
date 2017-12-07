#include"Stage.h"

// ������, �Ҹ���
Stage::Stage() {
}
Stage::~Stage(){
}

// ������ getter, setter
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
void Stage::start(Ranking* rank) { // ������ �帧
	begin = clock(); // ������ �ð� ����
	hero = new Hero(); // ���� ����
	item = new ItemHouse<Item>(); // ������ ����
	
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
		monsterDatabase->getMonsterBullet()->moveBullet(hero);
		item->showItem(&buffer);

		count++;

		score = score + monsterDatabase->whenCrashWithHero(hero);
		score = score + monsterDatabase->whenCrashWithBullet(hero);

		////////////////////  Ű���� �Է� ���� ///////////////////////////
		if(GetAsyncKeyState(VK_UP)!=0) { // ���� ����Ű
			hero->move(72);
        }
		if(GetAsyncKeyState(VK_DOWN)!=0) { // �Ʒ��� ����Ű
			hero->move(80);
        }
		if(GetAsyncKeyState(VK_LEFT)!=0) { // ���� ����Ű
			hero->move(75);
        }
		if(GetAsyncKeyState(VK_RIGHT)!=0) { // ������ ����Ű
			hero->move(77);
        }
        if(GetAsyncKeyState(0x42)!=0 && hero->getBombCount() > 0) { // B�� ������, ��ź�� 1�� �̻��϶�
			score = score + monsterDatabase->whenHeroUseBomb(hero->getBombDamage()); // ���� �����ͺ��̽��� ������ ��ź ���ݷ� ��ŭ�� ���ظ� ��
			hero->setBombCount(hero->getBombCount() - 1); // ��ź ���� ����
        }
		if(GetAsyncKeyState(VK_SPACE)!=0 && hero->getTime() <= 0) { // SPACE�� ������, �Ѿ� ���ð��� �����Ͽ��� ��
			hero->setTime(10); // ���� ���ð� �ʱ�ȭ
			hero->attack(); // �Ѿ� ����
        }
		showMap();
	}
	buffer.Release(); // ȭ�� ���۸� ��������
	system("cls");

	char name[40];
	cout << "���!!!" << endl;
	cout << "�ı����� : " << score * 100 << "    �ð����� : " << ((end-begin)/CLOCKS_PER_SEC * 100) << endl;
	cout << "����� ���� �̸��� �Է��� �ּ��� : ";
	scanf("%s",name);
	rank->getDatabase()->addRank((score+(end-begin)/CLOCKS_PER_SEC)*100, name);
	system("cls");
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
	monsterDatabase->getMonsterBullet()->printBullet(buffer);

	item->showItem(&buffer);
	
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
#include"Stage.h"

// ������, �Ҹ���
Stage::Stage() {
}
Stage::~Stage(){
}

// 변수의 getter, setter
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

// 함수
void Stage::start(Ranking* rank) { //게임의 흐름
	begin = clock();
	hero = new Hero(); // 영웅 생성
	item = new ItemHouse(); //아이템 생성
	
	monsterDatabase = new MonsterDatabase();
	
	score = 0;
	gameRunSpead = 20;
	int count = 0;

	// 화면 버퍼 생성
	buffer.CreateBuffer();

	// 화면 출력
	showMap();

	while(hero->getHp() > 0 && !monsterDatabase->getBossDied()) { // �ϴ��� ������ �ױ� ������ ����
		if(hero->getTime() > 0) { // ������ ���� ���ð� ����
			hero->setTime(hero->getTime()-1);
		}

		hero->getHeroBullet()->moveBullet(); // 총알의 움직임 및 움직임이 있을 시 화면 전환

		//몬스터 생성 및 이동
		if(count % gameRunSpead == 0){
			//게임 난이도에 따라 속도가 달라진다.
			monsterDatabase->moveMonster();
			if(monsterDatabase->getBoss() != NULL)
				monsterDatabase->getBoss()->move();
			if(count % (gameRunSpead*2) == 0){
				//게임 난이도에 따라 몬스터 생성 속도도 다르다.
				//움직이는 것의 1/2배 정도 되는 속도로 생성된다.
				srand((unsigned int)time(NULL));
				monsterDatabase->randomCreateMonster();
			}
		}

		monsterDatabase->getMonsterBullet()->moveBullet(hero);
		//boss Monster
		if((this->getScore() > 1) && (monsterDatabase->getBoss() == NULL)){
			monsterDatabase->createBossMoster();
		}
		
		item->showItem();
		item->getItemDatabase()->timeFlow();
		
		count++;
		
		score = score + item->getItemDatabase()->whenEatenbyHero(hero);
		score = score + monsterDatabase->whenCrashWithHero(hero);
		score = score + monsterDatabase->whenCrashWithBullet(hero);
		if(monsterDatabase->getBoss() != NULL)
			score = score + monsterDatabase->whenBossMCrashWithBullet(hero);

		////////////////////  키보드 입력 수정 ///////////////////////////
		if(GetAsyncKeyState(VK_UP)!=0) { // 위쪽 방향키
			hero->move(72);
        }
		if(GetAsyncKeyState(VK_DOWN)!=0) { // 아래쪽 방향키
			hero->move(80);
        }
		if(GetAsyncKeyState(VK_LEFT)!=0) { // 왼쪽 방향키
			hero->move(75);
        }
		if(GetAsyncKeyState(VK_RIGHT)!=0) { // 오른쪽 방향키
			hero->move(77);
        }
        if(GetAsyncKeyState(0x42)!=0 && hero->getBombCount() > 0) { // B를 누르고, 폭탄이 1개 이상일때
			score = score + monsterDatabase->whenHeroUseBomb(hero->getBombDamage()); // 몬스터 데이터베이스에 영웅의 폭탄 공격력 만큼의 피해를 줌
			hero->setBombCount(hero->getBombCount() - 1); // 폭탄 개수 감소
        }
		if(GetAsyncKeyState(VK_SPACE)!=0 && hero->getTime() <= 0) { // SPACE를 누르고, 총알 대기시간을 만족하였을 때
			hero->setTime(10); // 공격 대기시간 초기화
			hero->attack(); // 총알 생성
        }
		showMap();
	}

	buffer.Release(); // 화면 버퍼를 제거해줌
	system("cls");

		

	char name[40];
	cout << "사망!!!" << endl;
	cout << "파괴점수 : " << score * 100 << "    시간점수 : " << ((end-begin)/CLOCKS_PER_SEC * 100) << endl;
	cout << "당신의 영문 이름을 입력해 주세요 : ";
	scanf("%s",name);
	rank->getDatabase()->addRank((score+(end-begin)/CLOCKS_PER_SEC)*100, name);
	system("cls");
	buffer.Release(); // ȭ�� ���۸� ��������
	printf("%d", score);

}
void Stage::showMap() { // 화면 출력해주는 부분
	// 틀 출력
	int i, j;
	buffer.BufferClear();
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 0, "■");
	}
	for(i = 0; i < 50; i++) {
		buffer.BufferWrite(0, i+1, "■");
		for(j = 0; j < 20; j++) {
		}
		buffer.BufferWrite((j+1)*2, i+1, "■");
	}
	for(i = 0; i < 22; i++) {
		buffer.BufferWrite(i*2, 51, "■");
	}

	// 총알 출력
	multimap<int, Bullet*>::iterator iter;
	hero->getHeroBullet()->printBullet(buffer);

	// 영웅 출력
	buffer.BufferWrite(hero->getCharacterX()*2+2, hero->getCharacterY()+1, hero->getShape());

	//Monster 출력
	monsterDatabase->print(buffer);
	monsterDatabase->getMonsterBullet()->printBullet(buffer);

	item->showItem();
	item->getItemDatabase()->printItem(buffer);
	
	// 출력 기본 위치 저장
	int printX = 46;
	int printY = 50;

	// 시간 출력
	end = clock();
	char convertString[40];
	itoa((end-begin)/CLOCKS_PER_SEC * 100, convertString, 10);
	buffer.BufferWrite(printX, printY, "Time : ");
	buffer.BufferWrite(printX+7, printY, convertString);

	// 점수 출력
	itoa(score * 100, convertString, 10);
	buffer.BufferWrite(printX, printY-1, "Score : ");
	buffer.BufferWrite(printX+8, printY-1, convertString);

	// 체력 출력
	buffer.BufferWrite(printX, printY-2, "HP : ");
	for(int i = 0; i < hero->getHp(); i++) {
		buffer.BufferWrite(printX+5+(i*2), printY-2, "♥");
	}

	// 폭탄 개수 출력
	buffer.BufferWrite(printX, printY-3, "BOMB : ");
	for(int i = 0; i < hero->getBombCount(); i++) {
		buffer.BufferWrite(printX+7+(i*2), printY-3, "◎");
	}

	//bossMonster hp ���
	if(monsterDatabase->getBoss() != NULL){
		itoa(monsterDatabase->getBoss()->getHp(), convertString, 10);
		buffer.BufferWrite(printX, printY-4, "MONHP : ");
		buffer.BufferWrite(printX+8, printY-4, convertString);
	}

	// ȭ�� ��ȯ

	buffer.Flipping();
}

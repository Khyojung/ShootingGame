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
bool Stage::start(int* monsterPoint, int* timePoint, int stageDifficult, Sound* sound) { //게임의 흐름
	begin = clock();
	hero = new Hero(); // 영웅 생성
	item = new ItemHouse(); //아이템 생성
	
	monsterDatabase = new MonsterDatabase(stageDifficult);
	
	score = 0;
	gameRunSpead = 20;
	int count = 0;

	// 화면 버퍼 생성
	buffer.CreateBuffer();

	// 화면 출력
	showMap(stageDifficult);

	while(hero->getHp() > 0 && !monsterDatabase->getBossDied()) { // �ϴ��� ������ �ױ� ������ ����
		if(hero->getTime() > 0) { // ������ ���� ���ð� ����
			hero->setTime(hero->getTime()-1);
		}
		if(hero->getMoveTime() > 0) {
			hero->setMoveTIme(hero->getMoveTime()-1);
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
		if(((getScore() > 100) || ((clock() - begin)/CLOCKS_PER_SEC > 50)) && (monsterDatabase->getBoss() == NULL)){
			monsterDatabase->createBossMoster(stageDifficult, sound);
		}
		
		item->showItem();
		item->getItemDatabase()->timeFlow();
		
		count++;
		
		score = score + item->getItemDatabase()->whenEatenbyHero(hero, sound);
		score = score + monsterDatabase->whenCrashWithHero(hero);
		score = score + monsterDatabase->whenCrashWithBullet(hero);
		if(monsterDatabase->getBoss() != NULL)
			score = score + monsterDatabase->whenBossMCrashWithBullet(hero);

		////////////////////  키보드 입력 수정 ///////////////////////////
		if(GetAsyncKeyState(VK_UP)!=0 && hero->getMoveTime() <= 0) { // 위쪽 방향키
			hero->move(72);
			hero->setMoveTIme(3);
        }
		if(GetAsyncKeyState(VK_DOWN)!=0 && hero->getMoveTime() <= 0) { // 아래쪽 방향키
			hero->move(80);
			hero->setMoveTIme(3);
        }
		if(GetAsyncKeyState(VK_LEFT)!=0 && hero->getMoveTime() <= 0) { // 왼쪽 방향키
			hero->move(75);
			hero->setMoveTIme(3);
        }
		if(GetAsyncKeyState(VK_RIGHT)!=0 && hero->getMoveTime() <= 0) { // 오른쪽 방향키
			hero->move(77);
			hero->setMoveTIme(3);
        }
        if(GetAsyncKeyState(0x42)!=0 && hero->getBombCount() > 0 && hero->getTime() <= 0) { // B를 누르고, 폭탄이 1개 이상일때
			hero->setTime(hero->getMinAttackTime()); // 공격 대기시간 초기화
			score = score + monsterDatabase->whenHeroUseBomb(hero->getBombDamage()); // 몬스터 데이터베이스에 영웅의 폭탄 공격력 만큼의 피해를 줌
			hero->setBombCount(hero->getBombCount() - 1); // 폭탄 개수 감소
			sound->soundPlay(2);
        }
		if(GetAsyncKeyState(VK_SPACE)!=0 && hero->getTime() <= 0) { // SPACE를 누르고, 총알 대기시간을 만족하였을 때
			hero->setTime(hero->getMinAttackTime()); // 공격 대기시간 초기화
			hero->attack(); // 총알 생성
			sound->soundPlay(0);
        }
		showMap(stageDifficult);
	}

	buffer.Release(); // 화면 버퍼를 제거해줌
	system("cls");

	
	*monsterPoint = score * 100 * stageDifficult;
	*timePoint = (clock()-begin)/CLOCKS_PER_SEC * 100 * stageDifficult;

	if(monsterDatabase->getBossDied()) {
		return true;
	}
	return false;
}
void Stage::showMap(int stageDifficult) { // 화면 출력해주는 부분
	// 틀 출력
	int i, j;
	buffer.BufferClear();
	//buffer.SetColor(8);
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
	//buffer.SetColor(13);
	multimap<int, Bullet*>::iterator iter;
	hero->getHeroBullet()->printBullet(buffer);

	// 영웅 출력
	//buffer.SetColor(15);
	buffer.BufferWrite(hero->getCharacterX()*2+2, hero->getCharacterY()+1, hero->getShape());

	// Monster 출력
	//buffer.SetColor(4);
	monsterDatabase->print(buffer);
	monsterDatabase->getMonsterBullet()->printBullet(buffer);

	// Item 출력
	buffer.SetColor(14);
	item->showItem();
	item->getItemDatabase()->printItem(buffer);
	buffer.SetColor(15);
	
	// 출력 기본 위치 저장
	int printX = 46;
	int printY = 50;
	//buffer.SetColor(6);

	// 시간 출력
	char convertString[40];
	itoa((clock()-begin)/CLOCKS_PER_SEC * 100 * stageDifficult, convertString, 10);
	buffer.BufferWrite(printX, printY, "Time : ");
	buffer.BufferWrite(printX+7, printY, convertString);

	// 점수 출력
	itoa(score * 100 * stageDifficult, convertString, 10);
	buffer.BufferWrite(printX, printY-1, "Score : ");
	buffer.BufferWrite(printX+8, printY-1, convertString);

	// 체력 출력
	buffer.BufferWrite(printX, printY-2, "HP : ");
	buffer.SetColor(12);
	for(int i = 0; i < hero->getHp(); i++) {
		buffer.BufferWrite(printX+5+(i*2), printY-2, "♥");
	}
	buffer.SetColor(15);

	// 폭탄 개수 출력
	buffer.BufferWrite(printX, printY-3, "BOMB : ");
	buffer.SetColor(14);
	for(int i = 0; i < hero->getBombCount(); i++) {
		buffer.BufferWrite(printX+7+(i*2), printY-3, "◎");
	}
	buffer.SetColor(15);

	// 난이도 출력
	itoa(stageDifficult, convertString, 10);
	buffer.BufferWrite(printX, printY-4, "LEVEL : ");
	buffer.BufferWrite(printX+8, printY-4, convertString);

	//bossMonster hp ���
	if(monsterDatabase->getBoss() != NULL){
		itoa(monsterDatabase->getBoss()->getHp(), convertString, 10);
		buffer.BufferWrite(printX, printY-5, "MONHP : ");
		buffer.BufferWrite(printX+8, printY-5, convertString);
	}
	/*
	// 색 확인용 출력 장소
	for(int i = 0; i < 2048; i++) {
		buffer.SetColor(i);
		buffer.BufferWrite(60+((i*2)%96), 1+(i/48), "■");
	}*/
	buffer.SetColor(15);
	buffer.Flipping();
}

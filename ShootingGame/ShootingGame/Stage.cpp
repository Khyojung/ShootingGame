#include"Stage.h"

// 생성자, 소멸자
Stage::Stage() { // 맵 초기화, 배열을 초기화 하는 부분을 삭제함, 이유는 객체로 관리하기 때문에 맵의 배열이 필요가 없음.
}
Stage::~Stage(){
}

// 변수의 getter, setter
// 이차원 배열 맵의 개터세터를 제거함. 이유는 이차원 배열 맵이 필요가 없기 때문에 이차원 배열 맵을 제거함.
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

// 함수
void Stage::start() { //게임의 흐름
	hero = new Hero(); // 영웅 생성

	// 화면 버퍼 생성
	buffer.CreateBuffer();

	// 화면 출력
	showMap();
	while(hero->getHp() > 0) { // 일단은 영웅이 죽기 전까지 실행
		if(hero->getTime() > 0) { // 영웅의 공격 대기시간 감소
			hero->setTime(hero->getTime()-1);
		}
		if(hero->getHeroBullet()->moveBullet()) { // 총알의 움직임 및 움직임이 있을 시 화면 전환
			showMap(); // 화면 전환
		}
		if(kbhit()) { // 키보드 입력이 있을 경우
			int key = getch(); // 키보드의 키를 입력 받는다
			if(key == 224 || key == 0) { // 방향키인가 검사
				key = getch(); // 키보드의 키를 한번더 받는다
				hero->move(key);
				// 캐릭터가 움직였으므로 여기서도 충돌 검사를 해야할까? 아니면 총알에서만의 충돌을 검사하면 될까? 이미 총알이 존재하는 곳으로 이동할 경우 어떻게 될것인가???
				// 그러면 충돌을 검사하는 부분은 Stage에서 총괄하는게 편할까, 아니면 각자의 객체가 충돌의 유무를 검사하는게 편할까?
				// 결국에는 서로서로가 남들을 각자 비교해보야하는 문제가 발생한다.
				showMap();
			}
			else if(key == 32 && hero->getTime() <= 0) { // 스페이스바 눌리면
				hero->setTime(10); // 공격 대기시간 초기화
				hero->attack(); // 총알 생성
				showMap(); // 화면 전환
			}
		}
	}
	buffer.Release(); // 화면 버퍼를 제거해줌
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

	// 화면 전환
	buffer.Flipping();
}
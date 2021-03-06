#include "BulletDatabase.h"

// 생성자, 소멸자
BulletDatabase::BulletDatabase() {
	bullet.clear();
	bullNumber = 0;
}
BulletDatabase::~BulletDatabase() {
}

// 변수의 getter, setter
map <int, Bullet*>* BulletDatabase::getBullet() {
	return &bullet;
}

// 함수
void BulletDatabase::addBullet(int bulletNumber, Bullet* newBullet) { // 총알 추가
	bullet.insert(pair<int,Bullet*> (bulletNumber, newBullet));
}
void BulletDatabase::delBullet(int bulletNumber) { // 총알 제거
	bullet.erase(bulletNumber);
}
void BulletDatabase::printBullet(screenBuffer buffer) { // 총알을 화면에 출력
	map<int, Bullet*>::iterator iter;
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		buffer.BufferWrite(iter->second->getCharacterX()*2+2, iter->second->getCharacterY()+1, iter->second->getShape()); // 총알의 X, Y좌표에 총알의 모양을 출력해준다.
	}
}
void BulletDatabase::moveBullet() { // 총알의 이동
	map<int, Bullet*>::iterator iter;
	map<int, int> temp;
	//bool moved = false; // 이동이 존재하였는지 확인
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		if(iter->second->getTime() > 0) { // 총알의 대기시간을 흐르도록 함
			iter->second->setTime(iter->second->getTime()-1);
		}
		if(iter->second->getTime() <= 0) { // 총알의 대기시간이 종료되었을 때 움직임
			if(iter->second->getCharacterY() <= 0) { // 만약 총알이 화면의 끝에 도착하였을 경우
				temp.insert(pair<int, int> (iter->first,iter->first)); // 제거할 총알의 번호를 임시의 temp map에 저장해 둠. 이유는 현재 위치에서 삭제할 경우 iter에 문제가 생김
			}
			else { // 화면의 끝이 아닐경우
				iter->second->setCharacterY(iter->second->getCharacterY()-1); // 총알의 Y좌표를 1감소시켜 위로 이동시킴.
				iter->second->setTime(2); // 총알의 대기시간을 초기화함
			}
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		delBullet(tempIter->second); // 반복자를 통하여 위에서 제거할 총알의 번호들에 해당하는 총알들을 제거해줌.
	}
}
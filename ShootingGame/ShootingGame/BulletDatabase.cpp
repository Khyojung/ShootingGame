#include "BulletDatabase.h"

BulletDatabase::BulletDatabase() {
}
BulletDatabase::~BulletDatabase() {
}
void BulletDatabase::addBullet(int bulletNumber, Bullet* newBullet) {
	bullet.insert(pair<int,Bullet*> (bulletNumber, newBullet));
}
void BulletDatabase::delBullet(int bulletNumber) {
	bullet.erase(bulletNumber);
}
void BulletDatabase::printBullet(screenBuffer buffer) {
	multimap<int, Bullet*>::iterator iter;
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		buffer.BufferWrite(iter->second->getCharacterX()*2+2, iter->second->getCharacterY()+1, iter->second->getShape());
	}
}
bool BulletDatabase::moveBullet() {
	multimap<int, Bullet*>::iterator iter;
	map<int, int> temp;
	bool moved = false;
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		if(iter->second->getTime() > 0) {
			iter->second->setTime(iter->second->getTime()-1);
		}
		if(iter->second->getTime() <= 0) {
			if(iter->second->getCharacterY() <= 0) {
				temp.insert(pair<int, int> (iter->first,iter->first));
			}
			else {
				iter->second->setCharacterY(iter->second->getCharacterY()-1);
				iter->second->setTime(3);
			}
			moved = true;
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		delBullet(tempIter->second);
	}
	return true;
}
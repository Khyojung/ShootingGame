#include "MonsterBulletDatabase.h"

// ������, �Ҹ���
MonsterBulletDatabase::MonsterBulletDatabase() {
	bullet.clear();
	bullNumber = 0;
}
MonsterBulletDatabase::~MonsterBulletDatabase() {
}

// ������ getter, setter
map <int, Bullet*>* MonsterBulletDatabase::getBullet() {
	return &bullet;
}

// �Լ�
void MonsterBulletDatabase::addBullet(int bulletNumber, Bullet* newBullet) { // �Ѿ� �߰�
	bullet.insert(pair<int,Bullet*> (bulletNumber, newBullet));
}
void MonsterBulletDatabase::delBullet(int bulletNumber) { // �Ѿ� ����
	bullet.erase(bulletNumber);
}
void MonsterBulletDatabase::printBullet(screenBuffer buffer) { // �Ѿ��� ȭ�鿡 ���
	map<int, Bullet*>::iterator iter;
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		buffer.BufferWrite(iter->second->getCharacterX()*2+2, iter->second->getCharacterY()+1, iter->second->getShape()); // �Ѿ��� X, Y��ǥ�� �Ѿ��� ����� ������ش�.
	}
}
void MonsterBulletDatabase::moveBullet(Hero* hero) { // �Ѿ��� �̵�
	map<int, Bullet*>::iterator iter;
	map<int, int> temp;
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		
		if(iter->second->getTime() > 0) { // �Ѿ��� ���ð��� �帣���� ��
			iter->second->setTime(iter->second->getTime()-1);
		}
		
		if(iter->second->getTime() <= 0) { // �Ѿ��� ���ð��� ����Ǿ��� �� ������
			if(iter->second->getCharacterY() >= 49) { // ���� �Ѿ��� ȭ���� ���� �����Ͽ��� ���
				temp.insert(pair<int, int> (iter->first,iter->first)); // ������ �Ѿ��� ��ȣ�� �ӽ��� temp map�� ������ ��. ������ ���� ��ġ���� ������ ��� iter�� ������ ����
			}
			else { // ȭ���� ���� �ƴҰ��
				iter->second->setCharacterY(iter->second->getCharacterY()+1); // �Ѿ��� Y��ǥ�� 1 �������� ���� �̵���Ŵ.
				iter->second->setTime(3); // �Ѿ��� ���ð��� �ʱ�ȭ��
			}
			if(iter->second->getCharacterX() == hero->getCharacterX() && iter->second->getCharacterY() == hero->getCharacterY()) {
				temp.insert(pair<int, int> (iter->first,iter->first)); // ĳ���Ϳ� ������ �Ѿ��� �浹
				hero->setHp(hero->getHp()+iter->second->getDamage()); // ĳ���� ü�� ����
			}
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		delBullet(tempIter->second); // �ݺ��ڸ� ���Ͽ� ������ ������ �Ѿ��� ��ȣ�鿡 �ش��ϴ� �Ѿ˵��� ��������.
	}
}
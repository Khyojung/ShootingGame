#include "BulletDatabase.h"

// ������, �Ҹ���
BulletDatabase::BulletDatabase() {
	bullNumber = 0;
}
BulletDatabase::~BulletDatabase() {
}

// �Լ�
void BulletDatabase::addBullet(int bulletNumber, Bullet* newBullet) { // �Ѿ� �߰�
	bullet.insert(pair<int,Bullet*> (bulletNumber, newBullet));
}
void BulletDatabase::delBullet(int bulletNumber) { // �Ѿ� ����
	bullet.erase(bulletNumber);
}
void BulletDatabase::printBullet(screenBuffer buffer) { // �Ѿ��� ȭ�鿡 ���
	multimap<int, Bullet*>::iterator iter;
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		buffer.BufferWrite(iter->second->getCharacterX()*2+2, iter->second->getCharacterY()+1, iter->second->getShape()); // �Ѿ��� X, Y��ǥ�� �Ѿ��� ����� ������ش�.
	}
}
bool BulletDatabase::moveBullet() { // �Ѿ��� �̵�
	multimap<int, Bullet*>::iterator iter;
	map<int, int> temp;
	bool moved = false; // �̵��� �����Ͽ����� Ȯ��
	for (iter = bullet.begin(); iter != bullet.end(); ++iter) {
		if(iter->second->getTime() > 0) { // �Ѿ��� ���ð��� �帣���� ��
			iter->second->setTime(iter->second->getTime()-1);
		}
		if(iter->second->getTime() <= 0) { // �Ѿ��� ���ð��� ����Ǿ��� �� ������
			if(iter->second->getCharacterY() <= 0) { // ���� �Ѿ��� ȭ���� ���� �����Ͽ��� ���
				temp.insert(pair<int, int> (iter->first,iter->first)); // ������ �Ѿ��� ��ȣ�� �ӽ��� temp map�� ������ ��. ������ ���� ��ġ���� ������ ��� iter�� ������ ����
			}
			//else if() {} // �̰����� ���߿� �浹�� Ȯ�����ִ� �κ��� �߰� �ɰ� ����. 
			else { // ȭ���� ���� �ƴҰ��
				iter->second->setCharacterY(iter->second->getCharacterY()-1); // �Ѿ��� Y��ǥ�� 1���ҽ��� ���� �̵���Ŵ.
				iter->second->setTime(3); // �Ѿ��� ���ð��� �ʱ�ȭ��
			}
			moved = true; // ������ �̵��� �̷�������Ƿ� moved�� true�� �ٲپ� ��.
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		delBullet(tempIter->second); // �ݺ��ڸ� ���Ͽ� ������ ������ �Ѿ��� ��ȣ�鿡 �ش��ϴ� �Ѿ˵��� ��������.
	}
	return moved; // �Ѿ��� ������ �̵��� ������ ��ȯ�� ��.
}
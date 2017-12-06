#include "ItemDatabase.h"

// ������, �Ҹ���

ItemDatabase::ItemDatabase() {
	itemCount = 0;
}

ItemDatabase::~ItemDatabase() {
}

// �Լ�

bool ItemDatabase::addItem(int itemNumber, Item* newItem) { // ������ �߰�
	if(itemCount <=5){
	map<int, Item*>::iterator iter;
	for(iter = item.begin(); iter != item.end(); ++iter){
		if((iter->second->getCharacterX() == newItem->getCharacterX())&&(iter->second->getCharacterY() == newItem->getCharacterY()))
			return false;

	}
	item.insert(pair<int,Item*> (itemNumber, newItem));
	itemCount++;
	}
	return true;
}

void ItemDatabase::delItem(int itemNumber) { // ������ ����
	item.erase(itemNumber);
}

void ItemDatabase::printItem(screenBuffer buffer) { // �������� ȭ�鿡 ���
	map<int, Item*>::iterator iter;
	for (iter = item.begin(); iter != item.end(); ++iter) {
		buffer.BufferWrite(iter->second->getCharacterX()*2+2, iter->second->getCharacterY()+1, iter->second->getShape()); // �Ѿ��� X, Y��ǥ�� �Ѿ��� ����� ������ش�.
	}
}

bool ItemDatabase::moveItem() { // �������� �̵�
	map<int, Item*>::iterator iter;
	map<int, int> temp;
	bool moved = false; // �̵��� �����Ͽ����� Ȯ��
	for (iter = item.begin(); iter != item.end(); ++iter) {
		if(iter->second->getTime() > 0) { // �������� ���ð��� �帣���� ��
			iter->second->setTime(iter->second->getTime()-1);
		}
		if(iter->second->getTime() <= 0) { // �������� ���ð��� ����Ǿ��� �� ������
			if(iter->second->getCharacterY() <= 0) { // ���� �������� ȭ���� ���� �����Ͽ��� ���
				temp.insert(pair<int, int> (iter->first,iter->first)); // ������ �������� ��ȣ�� �ӽ��� temp map�� ������ ��. ������ ���� ��ġ���� ������ ��� iter�� ������ ����
			}
			//else if() {} // �̰����� ���߿� �浹�� Ȯ�����ִ� �κ��� �߰� �ɰ� ����. 
			else { // ȭ���� ���� �ƴҰ��
				iter->second->setCharacterY(iter->second->getCharacterY()+1); // �������� Y��ǥ�� 1�������� �Ʒ��� �̵���Ŵ.
				iter->second->setTime(3); // �������� ���ð��� �ʱ�ȭ��
			}
			moved = true; // ������ �̵��� �̷�������Ƿ� moved�� true�� �ٲپ� ��.
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		delItem(tempIter->second); // �ݺ��ڸ� ���Ͽ� ������ ������ �������� ��ȣ�鿡 �ش��ϴ� �����۵��� ��������.
	}
	return moved; // �������� ������ �̵��� ������ ��ȯ�� ��.
}
/*
* ����ΰ� �������� �Ծ��� �� �������� ȭ�鿡�� ������
*/
int ItemDatabase::whenEatenbyHero(Hero* hero) {

	map<int, Item*>::iterator iter;
	map<int, int> temp;
	int score = 0;
	
	for (iter = item.begin(); iter != item.end(); ++iter) {
		if(iter->second->getCharacterX() == hero->getCharacterX() && iter->second->getCharacterY() == hero->getCharacterY()) {
			iter->second->setHp(0);
			 score += iter->second->itemFunction(hero);
			temp.insert(pair<int, int> (iter->first,iter->first)); 
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		this->delItem(tempIter->second); // �ݺ��ڸ� ���Ͽ� �������� �������ش�.
		itemCount--;
		
	}

	return score;
}
void ItemDatabase::timeFlow(){
	map<int, Item*>::iterator iter;
	map<int, int> temp;
	
	for (iter = item.begin(); iter != item.end(); ++iter) {
		if((clock()-iter->second->getBegin())/CLOCKS_PER_SEC > 5) {
			temp.insert(pair<int, int> (iter->first,iter->first)); 
		}
	}
	map<int, int>::iterator tempIter;
	for(tempIter = temp.begin();tempIter != temp.end(); ++tempIter) {
		this->delItem(tempIter->second); // �ݺ��ڸ� ���Ͽ� �������� �������ش�.
		itemCount--;
		
	}

}
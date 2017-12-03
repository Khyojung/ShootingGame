#include "ItemDatabase.h"

// ������, �Ҹ���

ItemDatabase<Item>::ItemDatabase() {
}

ItemDatabase<Item>::~ItemDatabase() {
}

// �Լ�

void ItemDatabase<Item>::addItem(int itemNumber, Item* newItem) { // ������ �߰�
	item.insert(pair<int,Item*> (itemNumber, newItem));
}

void ItemDatabase<Item>::delItem(int itemNumber) { // ������ ����
	item.erase(itemNumber);
}

void ItemDatabase<Item>::printItem(screenBuffer* buffer) { // �������� ȭ�鿡 ���
	multimap<int, Item*>::iterator iter;
	for (iter = item.begin(); iter != item.end(); ++iter) {
		buffer->BufferWrite(iter->second->getCharacterX()*2+2, iter->second->getCharacterY()+1, iter->second->getShape()); // �Ѿ��� X, Y��ǥ�� �Ѿ��� ����� ������ش�.
	}
}

bool ItemDatabase<Item>::moveItem() { // �������� �̵�
	multimap<int, Item*>::iterator iter;
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
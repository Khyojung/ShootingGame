#include "Hero.h"

// ������, �Ҹ���
Hero::Hero() { // ������� �⺻ �Ӽ� ����
	setHp(10);
	setSpeed(1);
	setDamage(1);
	setTime(10);
	setCharacterX(10);
	setCharacterY(49);
	setShape("��");
	bulletCount=0;

	// �Ѿ� �����ͺ��̽� �ʱ�ȭ
	heroBullet = new BulletDatabase();
}
Hero::~Hero() {
}

// ������ getter, setter
BulletDatabase* Hero::getHeroBullet()  {
	return heroBullet;
}
void Hero::setHeroBullet(BulletDatabase* newBulletDatabase) {
	heroBullet = newBulletDatabase;
}

// �Լ�
void Hero::move(int keyboard) { // ĳ������ �̵�
	// ����
	if(keyboard == 72 && this->getCharacterY() > 0) {
		this->setCharacterY(this->getCharacterY()-1);
	}

	// �Ʒ���
	if(keyboard == 80 && this->getCharacterY() < 49) {
		this->setCharacterY(this->getCharacterY()+1);
	}

	// ����
	if(keyboard == 75 && this->getCharacterX() > 0) {
		this->setCharacterX(this->getCharacterX()-1);
	}

	// ������
	if(keyboard == 77 && this->getCharacterX() < 19) {
		this->setCharacterX(this->getCharacterX()+1);
	}
}
void Hero::attack() { // �Ѿ˻���
	Bullet* newBullet = new Bullet(); // �Ѿ��� �⺻ �Ӽ� ����
	newBullet->setCharacterX(getCharacterX());
	newBullet->setCharacterY(getCharacterY()-1);
	newBullet->setDamage(getDamage());
	newBullet->changeShape(); // �Ѿ��� ���ݷ��� �������� ����� �ٲپ� ��.
	newBullet->setTime(3);

	// �����ͺ��̽��� �Ѿ� �߰�
	heroBullet->addBullet(bulletCount, newBullet);
	bulletCount++;
}
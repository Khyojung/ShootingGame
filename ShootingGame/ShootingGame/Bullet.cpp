#include "Bullet.h"

// ������, �Ҹ���
Bullet::Bullet() {
}
Bullet::Bullet(int newX, int newY){
	x = newX;
	y = newY;
}
Bullet::~Bullet() {
}

// �Լ�
void Bullet::changeShape() { // �Ѿ��� ���ݷ¿� �ش��ϴ� ����� ����
	if(getDamage() < 0) {
		setShape("��");
	}
	else if(getDamage() == 1) {
		setShape("��");
	}
	else if(getDamage() == 2) {
		setShape("��");
	}
	else if(getDamage() == 3) {
		setShape("��");
	}
	else if(getDamage() == 4) {
		setShape("��");
	}
	else if(getDamage() >= 5) {
		setShape("��");	
	}
}
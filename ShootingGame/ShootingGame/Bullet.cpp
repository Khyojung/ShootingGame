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
	switch(getDamage()) {
	case 1:
		setShape("��");
		break;
	case 2:
		setShape("��");
		break;
	case 3:
		setShape("��");
		break;
	case 4:
		setShape("��");
		break;
	case 5:
		setShape("��");
		break;
	default:
		break;
	}
}
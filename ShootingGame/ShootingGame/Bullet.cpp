#include "Bullet.h"

// 생성자, 소멸자
Bullet::Bullet() {
}
Bullet::Bullet(int newX, int newY){
	x = newX;
	y = newY;
}
Bullet::~Bullet() {
}

// 함수
void Bullet::changeShape() { // 총알의 공격력에 해당하는 모양을 설정
	switch(getDamage()) {
	case 1:
		setShape("Ⅰ");
		break;
	case 2:
		setShape("Ⅱ");
		break;
	case 3:
		setShape("Ⅲ");
		break;
	case 4:
		setShape("‡");
		break;
	case 5:
		setShape("º");
		break;
	default:
		break;
	}
}
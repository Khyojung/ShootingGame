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
	if(getDamage() < 0) {
		setShape("＊");
	}
	else if(getDamage() == 1) {
		setShape("Ⅰ");
	}
	else if(getDamage() == 2) {
		setShape("Ⅱ");
	}
	else if(getDamage() == 3) {
		setShape("Ⅲ");
	}
	else if(getDamage() == 4) {
		setShape("‡");
	}
	else if(getDamage() >= 5) {
		setShape("º");	
	}
}
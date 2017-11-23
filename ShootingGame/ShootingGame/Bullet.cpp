#include "Bullet.h"

Bullet::Bullet() {
}
Bullet::~Bullet() {
}
void Bullet::changeShape() {
	switch(getDamage()) {
	case 1:
		setShape("¥°");
		break;
	case 2:
		setShape("¥±");
		break;
	case 3:
		setShape("¥²");
	}
}
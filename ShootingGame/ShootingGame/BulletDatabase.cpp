#pragma once
#include "BulletDatabase.h"

using namespace std;

BulletDatabase::BulletDatabase() {
}
BulletDatabase::~BulletDatabase() {
}
void BulletDatabase::addBullet(int bulletNumber, Bullet* newBullet) {
	bullet.insert(pair<int,Bullet*> (bulletNumber, newBullet));
}
void BulletDatabase::delBullet(int bulletNumber) {
	bullet.erase(bulletNumber);
}
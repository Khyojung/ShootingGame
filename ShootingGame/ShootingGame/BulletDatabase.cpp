#include<iostream>
#include<map>
#include"Bullet.h"

using namespace std;

class BulletDatabase{
	
private:
	map <int, Bullet*> bullet;
public:
	BulletDatabase();
	~BulletDatabase();
	void addBuller(int, string);
	void delBullet();

};
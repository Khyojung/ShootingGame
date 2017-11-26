#pragma once
#include"Character.h"

class Bullet : public Character {	
private:
	int x;
	int y;

public:
	Bullet();
	Bullet(int x, int y);
	~Bullet();

	void changeShape();
};
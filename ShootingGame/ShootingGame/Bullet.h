#pragma once
#include<iostream>
#include"Character.h"

using namespace std;

class Bullet : public Character{
	
private:

public:
	Bullet();
	~Bullet();
	void move();

	void changeShape();

};
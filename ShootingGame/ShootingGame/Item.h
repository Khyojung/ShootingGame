#pragma once
#include<iostream>
#include"Hero.h"

#include <cstdlib>
#include <ctime>

using namespace std;
class Item : public Character{
	
private:
	int randomx;
	int randomy;

public:
	Item();
	~Item();

	//�� �������� ���
	virtual void itemFunction(Hero*) = 0;
	int itemRandomX();
	int itemRandomY();


};
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
	int score;


public:
	Item();
	~Item();

	//�� �������� ���
	virtual int itemFunction(Hero*) = 0;
	int itemRandomX();
	int itemRandomY();

	int getScore();
	void setScore(int );


};
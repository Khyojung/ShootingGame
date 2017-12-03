#pragma once
#include<iostream>
#include"Character.h"

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

	//각 아이템의 기능
	void itemFunction();
	int itemRandomX();
	int itemRandomY();


};
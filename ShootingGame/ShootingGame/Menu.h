#pragma once
#include<iostream>

using namespace std;

class Menu {
private:
	int menuSelect;

public:
	Menu();
	~Menu();

	int getMenuSelect();
	void setMenuSelect(int);

	void run();
};
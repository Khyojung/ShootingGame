#pragma once
#include <iostream>
#include "Ranking.h"

using namespace std;

class Start {
private:
	int level;

public:
	Start();
	~Start();

	int getLevel();
	void setLevel(int);

	void gameStart(Ranking*);
};
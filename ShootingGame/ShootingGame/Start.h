#include<iostream>

using namespace std;

class Start{
	
private:
	int level;
public:
	Start();
	~Start();
	void gameStart(int);

	int getLevel();
	void setLevel(int);

};
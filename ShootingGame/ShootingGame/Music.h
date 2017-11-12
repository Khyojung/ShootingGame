#include<iostream>

using namespace std;

class Music{
	
private:
	bool musicOn;
public:
	Music();
	~Music();
	bool getOn();
	void setOn(bool);
	void musicPlay();

};
#include<iostream>

using namespace std;

class Sound{
	
private:
	bool souncOn;
public:
	Sound();
	~Sound();
	bool getSounOn();
	void setSoundOn(bool);
	void soundPlay();

};
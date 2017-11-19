#pragma once
#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

class Sound{
	
private:
	bool soundOn;
public:
	Sound();
	~Sound();
	bool getSounOn();
	void setSoundOn(bool);
	void soundPlay();

};
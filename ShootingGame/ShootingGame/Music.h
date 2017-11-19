#pragma once
#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

class Music{
	
private:
	bool musicOn;
public:
	Music();
	~Music();
	string isMusicOn();
	bool getMusicOn();
	void setMusicOn(bool);
	void musicPlay();

};
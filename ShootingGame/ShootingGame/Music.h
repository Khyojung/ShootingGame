#pragma once
#include <Windows.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

class Music{
private:
	bool musicOn;

public:
	Music();
	~Music();
	
	bool getMusicOn();
	void setMusicOn(bool);

	char* isMusicOn();
	void musicPlay();
};
#pragma once
#include <Windows.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")

class Sound {
private:
	bool soundOn;

public:
	Sound();
	~Sound();

	bool getSounOn();
	void setSoundOn(bool);

	char* isSoundOn();
	void soundPlay();

};
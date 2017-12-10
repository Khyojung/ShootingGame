#pragma once
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <MMSystem.h>
#include <Digitalv.h>

class Sound {
private:
	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;
	UINT wDeviceID;
	DWORD Sound1, Sound2, Sound3, Sound4;
	bool soundOn;
	int dwID;

public:
	Sound();
	~Sound();

	bool getSounOn();
	void setSoundOn(bool);

	char* isSoundOn();
	void soundPlay(int);
	DWORD LoadWAV(LPCTSTR);
};
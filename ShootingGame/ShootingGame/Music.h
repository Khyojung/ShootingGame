#pragma once
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include <MMSystem.h>
#include <Digitalv.h>

class Music{
private:
	MCI_OPEN_PARMS m_mciOpenParms;
	MCI_PLAY_PARMS m_mciPlayParms;
	DWORD m_dwDeviceID;

	bool musicOn;
	int dwID;

public:
	Music();
	~Music();
	
	bool getMusicOn();
	void setMusicOn(bool);

	char* isMusicOn();
	void musicPlay();
};
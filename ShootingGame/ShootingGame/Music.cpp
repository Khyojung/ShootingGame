#include "Music.h"

// 생성자, 소멸자
Music::Music() {
	m_mciOpenParms.lpstrElementName = L"Planet Popstar.mp3";
	m_mciOpenParms.lpstrDeviceType = L"mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&m_mciOpenParms);

	dwID = m_mciOpenParms.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
}
Music::~Music() {
}

// 변수의 getter, setter
bool Music::getMusicOn() {
	return musicOn;
}
void Music::setMusicOn(bool isTrue) {
	musicOn = isTrue;
}

// 함수	
char* Music::isMusicOn() { // 음악이 켜져있으면 On을 반환, 꺼져있으면 Off를 반환
	if(musicOn) {
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&m_mciOpenParms);
		dwID = m_mciOpenParms.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
		return "On";
	}
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
	return "Off";
}
void Music::musicPlay() { // 음악을 재생한다. 아래의 주석처리된 부분은 음악을 멈추는데 사용될 부분이다.
	if(musicOn) {
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
	}
}
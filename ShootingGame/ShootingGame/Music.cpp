#include "Music.h"

// ������, �Ҹ���
Music::Music() {
	m_mciOpenParms.lpstrElementName = L"Planet Popstar.mp3";
	m_mciOpenParms.lpstrDeviceType = L"mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&m_mciOpenParms);

	dwID = m_mciOpenParms.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
}
Music::~Music() {
}

// ������ getter, setter
bool Music::getMusicOn() {
	return musicOn;
}
void Music::setMusicOn(bool isTrue) {
	musicOn = isTrue;
}

// �Լ�	
char* Music::isMusicOn() { // ������ ���������� On�� ��ȯ, ���������� Off�� ��ȯ
	if(musicOn) {
		mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&m_mciOpenParms);
		dwID = m_mciOpenParms.wDeviceID;
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
		return "On";
	}
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
	return "Off";
}
void Music::musicPlay() { // ������ ����Ѵ�. �Ʒ��� �ּ�ó���� �κ��� ������ ���ߴµ� ���� �κ��̴�.
	if(musicOn) {
		mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&m_mciPlayParms);
	}
}
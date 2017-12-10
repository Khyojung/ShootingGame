#include "Sound.h"

// 생성자, 소멸자
Sound::Sound() {
}
Sound::~Sound() {
}

// 변수의 getter, setter
bool Sound::getSounOn() {
	return soundOn;
}
void Sound::setSoundOn(bool isTrue) {
	soundOn = isTrue;
}

// 함수
char* Sound::isSoundOn() { // 소리가 켜져있으면 On을 반환, 꺼져있으면 Off를 반환
	if(soundOn)
		return "On";
	return "Off";
}
void Sound::soundPlay(int sound) { // 소리를 재생한다. 아래의 주석처리된 부분은 음악을 멈추는데 사용될 부분이다.
	if(soundOn) {
		switch(sound) {
		case 0: // 공격할때
			Sound1 = LoadWAV(L"Sound1.mp3");
			Sound1 = mciSendCommand(2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID) NULL);
			Sound1 = mciSendCommand(2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
			break;
		case 1: // 아이템먹을때
			Sound2 = LoadWAV(L"Sound2.mp3");
			Sound2 = mciSendCommand(3, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID) NULL);
			Sound2 = mciSendCommand(3, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
			break;
		case 2: // 폭탄
			Sound3 = LoadWAV(L"Sound3.mp3");
			Sound3 = mciSendCommand(4, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID) NULL);
			Sound3 = mciSendCommand(4, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
			break;
		case 3: // 보스 등장
			Sound4 = LoadWAV(L"Sound4.mp3");
			Sound4 = mciSendCommand(5, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID) NULL);
			Sound4 = mciSendCommand(5, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
			break;
		default:
			break;
		}
	}
}
DWORD Sound::LoadWAV(LPCTSTR lpszWave) {
	wDeviceID = 0;
	DWORD Result;

	m_mciOpenParms.lpstrDeviceType = L"mpegvideo";

	m_mciOpenParms.lpstrElementName = lpszWave;

	Result = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID) & m_mciOpenParms);

	if(Result)
		return Result;

	wDeviceID = m_mciOpenParms.wDeviceID;

	m_mciPlayParms.dwCallback = 0;

	if(Result)
		return Result;

	return 0;
}


/*

		if(sound == 3) { // 보스등장
			m_mciOpenParms.lpstrElementName = L"Sound4.mp3";
			m_mciOpenParms.lpstrDeviceType = L"mpegvideo";

			mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&m_mciOpenParms);

			dwID = m_mciOpenParms.wDeviceID;

			mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID) NULL);
			mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
		}
		*/
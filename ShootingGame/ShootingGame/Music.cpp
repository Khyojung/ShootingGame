#include "Music.h"

// ������, �Ҹ���
Music::Music() {
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
	if(musicOn)
		return "On";
	return "Off";
}
void Music::musicPlay() { // ������ ����Ѵ�. �Ʒ��� �ּ�ó���� �κ��� ������ ���ߴµ� ���� �κ��̴�.
	if(musicOn) {
		PlaySound(TEXT("GUNFIRE.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		// sndPalySound(NULL, SND_ASYNC);
	}
}
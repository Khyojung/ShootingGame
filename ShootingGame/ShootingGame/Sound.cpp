#include "Sound.h"

// ������, �Ҹ���
Sound::Sound() {
}
Sound::~Sound() {
}

// ������ getter, setter
bool Sound::getSounOn() {
	return soundOn;
}
void Sound::setSoundOn(bool isTrue) {
	soundOn = isTrue;
}

// �Լ�
char* Sound::isSoundOn() { // �Ҹ��� ���������� On�� ��ȯ, ���������� Off�� ��ȯ
	if(soundOn)
		return "On";
	return "Off";
}
void Sound::soundPlay() { // �Ҹ��� ����Ѵ�. �Ʒ��� �ּ�ó���� �κ��� ������ ���ߴµ� ���� �κ��̴�.
	if(soundOn) {
		PlaySound(TEXT("GUNFIRE.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		// sndPalySound(NULL, SND_ASYNC);
	}
}
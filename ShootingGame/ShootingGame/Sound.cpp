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
void Sound::soundPlay() { // 소리를 재생한다. 아래의 주석처리된 부분은 음악을 멈추는데 사용될 부분이다.
	if(soundOn) {
		PlaySound(TEXT("GUNFIRE.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		// sndPalySound(NULL, SND_ASYNC);
	}
}
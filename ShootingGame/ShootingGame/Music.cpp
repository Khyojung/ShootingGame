#include "Music.h"

// 생성자, 소멸자
Music::Music() {
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
	if(musicOn)
		return "On";
	return "Off";
}
void Music::musicPlay() { // 음악을 재생한다. 아래의 주석처리된 부분은 음악을 멈추는데 사용될 부분이다.
	if(musicOn) {
		PlaySound(TEXT("GUNFIRE.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		// sndPalySound(NULL, SND_ASYNC);
	}
}
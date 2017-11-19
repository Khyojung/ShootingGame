#include "Sound.h"

Sound::Sound() {
}
Sound::~Sound() {
}
bool Sound::getSounOn() {
	return soundOn;
}
void Sound::setSoundOn(bool isTrue) {
	soundOn = isTrue;
}
void Sound::soundPlay() {
	if(soundOn) {
		PlaySound(TEXT("GUNFIRE.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		// sndPalySound(NULL, SND_ASYNC);
	}
}
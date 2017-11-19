#include "Music.h"

Music::Music() {
}
Music::~Music() {
}
string Music::isMusicOn() {
	if(musicOn)
		return "On";
	return "Off";
}
bool Music::getMusicOn() {
	return musicOn;
}
void Music::setMusicOn(bool isTrue) {
	musicOn = isTrue;
}
void Music::musicPlay() {
	if(musicOn) {
		PlaySound(TEXT("GUNFIRE.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		// sndPalySound(NULL, SND_ASYNC);
	}
}
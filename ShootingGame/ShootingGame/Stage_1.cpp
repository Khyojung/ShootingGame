#include "Stage_1.h"

// ������, �Ҹ���
Stage_1::Stage_1() {
	Stage();
}
Stage_1::~Stage_1() {
}

void Stage_1::run(int* monsterPoint, int* timePoint, Sound* sound) {
	if(start(monsterPoint, timePoint, 1, sound)) {
		if(start(monsterPoint, timePoint, 3, sound)) {
			start(monsterPoint, timePoint, 5, sound);
		}
	}
}
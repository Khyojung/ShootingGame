#include "Stage_2.h"

// ������, �Ҹ���
Stage_2::Stage_2() {
	Stage();
}
Stage_2::~Stage_2() {
}

void Stage_2::run(int* monsterPoint, int* timePoint, Sound* sound) {
	if(start(monsterPoint, timePoint, 3, sound)) {
		start(monsterPoint, timePoint, 5, sound);
	}
}
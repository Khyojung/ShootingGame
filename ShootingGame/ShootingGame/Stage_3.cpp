#include "Stage_3.h"

// ������, �Ҹ���
Stage_3::Stage_3() {
	Stage();
}
Stage_3::~Stage_3() {
}

void Stage_3::run(int* monsterPoint, int* timePoint, Sound* sound) {
	if(start(monsterPoint, timePoint, 5, sound))
		printf("You Win!");
}
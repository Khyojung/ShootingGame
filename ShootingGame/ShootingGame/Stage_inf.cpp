#include "Stage_inf.h"

// ������, �Ҹ���
Stage_inf::Stage_inf() {
	Stage();
}
Stage_inf::~Stage_inf() {
}

void Stage_inf::run(int* monsterPoint, int* timePoint, Sound* sound) {
	int i = 2;
	while(start(monsterPoint, timePoint, i, sound)) {
		i = i * 2;
	}
}
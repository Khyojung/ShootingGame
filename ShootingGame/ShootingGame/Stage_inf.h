#pragma once
#include"Stage.h"

class Stage_inf : public Stage {
private:

public:
	Stage_inf();
	~Stage_inf();

	void run(int*, int*, Sound*);
};
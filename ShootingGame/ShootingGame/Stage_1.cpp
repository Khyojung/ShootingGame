#include "Stage_1.h"
#include "screenBuffer.h"

Stage_1::Stage_1(){
	Stage();
}

Stage_1::~Stage_1(){

}

void Stage_1::start() {
	int i,j;
	Hero hero;
	hero.setStage(this);
	hero.getStage()->setMapXY(10, 49,-1);
	CreateBuffer();
	BufferClear();
	for(i = 0; i < 22; i++) {
		BufferWrite(i*2, 0, "бс");
	}
	for(i = 0; i < 50; i++) {
		BufferWrite(0, i+1, "бс");
		for(j = 0; j < 20; j++) {
			if(getMap()[i][j] == 0) {
				BufferWrite((j+1)*2, i+1, "  ");
			}
			if(getMap()[i][j] == -1) {
				BufferWrite((j+1)*2, i+1, hero.getShape());
			}
		}
		BufferWrite((j+1)*2, i+1, "бс");
	}
	for(i = 0; i < 22; i++) {
		BufferWrite(i*2, 51, "бс");
	}
	Flipping();
	while(1) {
		if(hero.getTime() > 0)
			hero.setTime(hero.getTime()-1);
		if(kbhit() && hero.getTime() == 0) {;
			int key = getch();
			if(key == 224 || key == 0) {
				key = getch();
				hero.move(key);
				hero.setTime(1000);
				CreateBuffer();
				BufferClear();
				for(i = 0; i < 22; i++) {
					BufferWrite(i*2, 0, "бс");
				}
				for(i = 0; i < 50; i++) {
					BufferWrite(0, i+1, "бс");
					for(j = 0; j < 20; j++) {
						if(getMap()[i][j] == 0) {
							BufferWrite((j+1)*2, i+1, "  ");
						}
						if(getMap()[i][j] == -1) {
							BufferWrite((j+1)*2, i+1, hero.getShape());
						}
					}
					BufferWrite((j+1)*2, i+1, "бс");
				}
				for(i = 0; i < 22; i++) {
					BufferWrite(i*2, 51, "бс");
				}
				Flipping();
			}
		}
	}
	Release();
}




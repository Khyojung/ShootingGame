#include"Monster.h"
#include"MonsterBoss.h"

MonsterBoss::MonsterBoss(){
	this->setCharacterX(1);
	this->setCharacterY(5);
	char* temp[6] = {"        □□□□□□□□        ",
					 "      □□□□□□□□□□      ",
					 "    □□□□□□□□□□□□    ",
					 "   □□□□□□□□□□□□□   ",
					 "◁□□□□□□□□□□□□□□▷",
					 "     ▽  ▽  ▽  ▽  ▽  ▽     "};
	setShape(temp);
	this->setHp(100);
	right = true;
	setDamage(-1);
	begin = clock();
}
MonsterBoss::~MonsterBoss(){
}

//getter setter
bool MonsterBoss::getRight(){
	return right;
}
void MonsterBoss::setRight(bool aRight){
	right = aRight;
}


//함수 재정의
void MonsterBoss::move(){
	if(right){
		this->setCharacterX(this->getCharacterX()+1);
		if((getCharacterX() + 15) >= 19)
			setRight(false);
	}
	else{
		this->setCharacterX(this->getCharacterX()-1);
		if(getCharacterX() <= 0)
			setRight(true);
	}
}
bool MonsterBoss::attack(){
	if(((clock()-begin)/CLOCKS_PER_SEC) > 0) {
		begin = clock();
		return true;
	}
	return false;
}
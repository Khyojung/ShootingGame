#include<iostream>

using namespace std;
class Menu{
	
private:
	int menuSelect;
public:
	Menu();
	~Menu();
	void run();

	int getMenuSelect();
	void setMenuSelect(int);

};
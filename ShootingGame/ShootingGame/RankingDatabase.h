#include<iostream>

using namespace std;
class RankingDatabase{
	
private:
	string userID;
	int score[];
public:
	RankingDatabase();
	~RankingDatabase();
	void addRank(int, string);
	void delRank();
	void sorting();

};
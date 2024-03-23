#include<iostream>
using namespace std;

class Player
{
	int j_no;
	char name[20];
	int runs;
	int matches;
	int wickets;
	
	public:
		Player();
		Player(int ,char* , int ,int ,int);
		void setJ_no(int);
		void setName(char* );
		void setRuns(int);
		void setMatches(int);
		void setWicket(int);
		int getJ_no();
		char* getName();
		int getRuns();
		int getMatches();
		int getWickets();
		void display();
};

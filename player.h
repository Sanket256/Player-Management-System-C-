
class Player
{
	int jerSeyNo;
	char name[30];
	int runs;
	int wickets;
	int matches;
	
	public:
		
	Player();
	Player(int,char*,int,int,int);

	int getJno();
	char* getName();
	int getRun();
	int getWicket();
	int getMatches();

	void setJno(int);
	void setName(char*);
	void setRun(int);
	void setWicket(int);
	void setMatches(int);

	void displayPlayer();
};
//void operator<<(ostream&,Player&);
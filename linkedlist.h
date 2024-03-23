#include"node.cpp"
//template<class T>
#include"fstream"
class LinkedList
{
	 Node<Player> *start;
	 
	 public:
	 	LinkedList();
	 	Node<Player>* getStart();
	 	void insertBeg(Player );
	 	void insertPos(Player,int);
	 	void deletePos(int);
	 	Node<Player>* searchPlayer(int);
	 	bool updateRuns(int ,int);
	 	bool updateWickets(int , int);
	 	bool updateMatches(int, int);
	 	void top3PlayersByRuns();
	 	void display();
		void writeDataToFile(const char* );
		void readDataFromFile(const char* );
};

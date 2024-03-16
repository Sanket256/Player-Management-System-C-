#include"node.h"
class LinkedList{

    Node* start;

    public:

    LinkedList();
    // void insertBeg(Node* );
	void addPlayerToPosition(Player&,int);
	void DeletePalyerFromPosition(int pos);	
	void displayInfo();
	bool searchPlayer(int);
	bool updatePlayer(int);
	void topThreePlayers();
    void readDataFromFile(const char* );
    void writeDataToFile(const char* );
	~LinkedList();
};
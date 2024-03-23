#include"linklist.h"
#include"fstream"

LinkedList::LinkedList()
{
	start=NULL;
}
//////////////////////////////////////////
void LinkedList::insertBeg(Player d)
{
	Node<Player> *temp = new  Node<Player>(d);
	temp->setNext(start);
	start = temp;
	
}
/////////////////////////////////
void LinkedList::insertPos(Player d,int pos)
{
	Node<Player> *temp=new Node<Player>(d);
	if(start == NULL)
	{
		start = temp;
		return;
	}
	if(pos == 1)
	{
		temp->setNext(start);
		start = temp;
		return;
	}
	int i=1;
	Node<Player> *p=start;
	while(i<pos-1 && p->getNext() != NULL)
	{
		p=p->getNext();
		i++;	
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
	display();
}
/////////////////////////////////
void LinkedList::deletePos(int pos)
{
		Node<Player> *p=start;
	if(start == NULL)
	{
		cout<<"\nNo element to delete";
		return;
	}
		
	else if(pos == 1)
	{
	
		start = p->getNext();
		p->getData().display();
		cout<<"\nPlayer is deleted successfully";
		delete p;
		
	}
	else
	{
		int i=1;
		while(i<pos-1 && p->getNext() != NULL)
		{
			p=p->getNext();
			i++;
		}
		if(i == pos-1 && p->getNext() != NULL)
		{
			Node<Player> *q=p->getNext();
			p->setNext(q->getNext());
			q->getData().display();
			cout<<"\nPlayer is deleted successfully";
			delete q;	
		}
		else
		{
			cout<<"\nInvalid Position";
		}
		
	}
}
/////////////////////////////////////////////
Node<Player> * LinkedList::searchPlayer(int j_no)
{
	Node<Player> *p = start;
	
	while(p != NULL)
	{
		if(j_no == p->getData().getJ_no())
		{
			return p;
		}
		p = p->getNext();
	}
	return NULL;
	
}
///////////////////////////////////////////
bool LinkedList::updateRuns(int j_no, int runs)
{
	Node<Player> *p = searchPlayer(j_no);
	if(p == NULL)
	{
		cout<<"\nNo player present";
		return false;
	}
	if(p != NULL)
	{
		Player f = p->getData();
		f.setRuns(runs);
		p->setData(f);
		return true;
	}
	else{
		cout<<"\nPlayer not found";
		return false;
	}
	
}
/////////////////////////////////////////
bool LinkedList::updateWickets(int j_no, int wicket)
{
	Node<Player> *p = searchPlayer(j_no);
	if(p == NULL)
	{
		cout<<"\nNo player present";
		return false;
	}
	if(p != NULL)
	{
		Player f = p->getData();
		f.setWicket(wicket);
		p->setData(f);
		return true;
	}
	else{
		cout<<"\nPlayer not found";
		return false;
	}
	
}
///////////////////////////////////////////
bool LinkedList::updateMatches(int j_no, int match)
{
	Node<Player> *p = searchPlayer(j_no);
	if(p == NULL)
	{
		cout<<"\nNo player present";
		return false;
	}
	if(p != NULL)
	{
		Player f = p->getData();
		f.setMatches(match);
		p->setData(f);
		return true;
	}
	else{
		cout<<"\nPlayer not found";
		return false;
	}
	
}
/////////////////////////////////////////
void  LinkedList::display()
{
	if(start == NULL)
	{
		cout<<"\nNo nodes to display";
		return;
	}
	else
	{
	cout << "+--------------+--------------+--------------+----------------+--------------+\n"; 
    cout << "| Jersey No    |   Name       | Runs         | Matches Player |    Wickets   |\n" ;
    cout << "+--------------+--------------+--------------+----------------+--------------+\n";
    
		Node<Player> *p = start;
		while(p!=NULL)
		{
			p->getData().display();
			p=p->getNext();  
			cout << "+--------------+--------------+--------------+----------------+--------------+\n";
		}
//	cout << "+--------------+--------------+--------------+----------------+--------------+\n";
    
	}	
}
/////////////////////////////////////////////////
void LinkedList::writeDataToFile(const char *fileName)
{
    ofstream outFile;
	outFile.open(fileName, ios::binary);
    if (!outFile)
    {
        cout << "*Error*\nFile not Opened";
        return;
    }
    Node<Player> *p = start;
    while (p != NULL)
    {
        // playerData = p->getData();
		outFile.write((char*)(&p->getData()),sizeof(Player));
        p = p->getNext();
    }
    outFile.close();
}
//////////////////////////////////////////////////////////////////////
void LinkedList::readDataFromFile(const char * fileName)
{
    ifstream inFile(fileName, ios::binary);
    if (!inFile)
    {
        cout << "*Error*\nFile not opened";
        return;
    }
    Player b;
    while(inFile.read((char *)(&b), sizeof(Player)))
    {
        this->insertBeg(b);
    }
    inFile.close();
}

//////////////////////////////////////////////////////////////////

void LinkedList::top3PlayersByRuns() {
    Node<Player> *first = nullptr;
    Node<Player> *second = nullptr;
    Node<Player> *third = nullptr;

    Node<Player> *current = start;
    while (current != nullptr) {
        Player currentPlayer = current->getData();

        if (first == nullptr || currentPlayer.getRuns() > first->getData().getRuns()) {
            third = second;
            second = first;
            first = current;
        } else if (second == nullptr || currentPlayer.getRuns() > second->getData().getRuns()) {
            third = second;
            second = current;
        } else if (third == nullptr || currentPlayer.getRuns() > third->getData().getRuns()) {
            third = current;
        }

        current = current->getNext();
    }
    cout << "Top 3 Players by Runs:\n";
    if (first != nullptr) {
        cout << "1. ";
        first->getData().display();
        cout << endl;
    }
    if (second != nullptr) {
        cout << "2. ";
        second->getData().display();
        cout << endl;
    }
    if (third != nullptr) {
        cout << "3. ";
        third->getData().display();
        cout << endl;
    }
}

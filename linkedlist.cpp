#include"linkedlist.h"
#include<fstream>
#include<stdlib.h>
LinkedList::LinkedList(){
    this->start=NULL;
	ifstream in("demo.bin",ios_base::binary);
	while(start!=NULL)
	{
		Node* p=start;
		in.read((char*)(&p->getData()),sizeof(p->getData()));
		if(in.eof())
		{
			break;
		}
		p->getData().displayPlayer();
		p=p->getNext();	
	}
	in.close();

}
void LinkedList::addPlayerToPosition(Player& player,int pos){
    Node* temp=new Node(player);
	if(start==NULL)
	{
		start=temp;
		return;
	}
	if(pos==1)
	{
		temp->setNext(start);
		start=temp;
		return;
	}
	int i=1;
	Node* p=start;
	while(i < pos-1 && p->getNext()!=NULL)
	{
		p=p->getNext();
		i++;
	}
	temp->setNext(p->getNext());
	p->setNext(temp);
}
void LinkedList::DeletePalyerFromPosition(int pos){
    if(start==NULL)
	{
		cout<<"\n No Player to delete  ";
		return;
	}
	
	Node*p=start;
	if(pos==1)
	{
		start=start->getNext();
		//p->getData().displayPlayer();
		cout<<"\n Player is deleted sucessfully !!!";
		delete p;
		return;
	}
	
	int i=1;
	while(i < pos-1 && p->getNext()!=NULL)
	{
		p=p->getNext();
		i++;
	}
	
	if(i==pos-1 && p->getNext()!=NULL)
	{
		Node* q=p->getNext();
		p->setNext(q->getNext());
		//q->getData().displayPlayer();
		cout<<"\n Player is deleted sucessfully !!!";
		delete q;
		return;
	}	
}	
void LinkedList::displayInfo(){
    if(start==NULL)
	{
		cout<<"\n No Player to display in Liked List ";
		return ;
	}
	else
	{
		Node *p=start;
		cout<<"\n\n Player information \n";
		//cout<<"\n |JercyNO       |  	Name     |   Runs      |  	Wicket    |  	Matches    |";
		while(p != NULL)
		{
			p->getData().displayPlayer();
			p=p->getNext();
		}
	}
}
bool LinkedList::searchPlayer(int jerSeyNo){
    if(start==NULL)
	{
		cout<<"\n No Player to search in Liked List ";
	}
	else
	{
		Node* p=start;
		while(p!=NULL)
		{
			if(p->getData().getJno()==jerSeyNo)
			{
                // p->getData()<<endl;
				return true;
			}
			else
			p=p->getNext();
		}
		return false;
	}
}
bool LinkedList::updatePlayer(int jerSeyNo){
    if(start==NULL)
	{
		cout<<"\n No player to update in Liked List ";
	}
	else
	{
		Node* p = start;
		while(p != NULL)
		{
			if(p->getData().getJno() == jerSeyNo)
			{
				int run,wicket,matches;
				cout<<"\n Enter the run ";
				cin>>run;
				cout<<"\n Enter the wicket ";
				cin>>wicket;
				cout<<"\n Enter the matches ";
				cin>>matches;
				
				Player &obj=p->getData();
				obj.setRun(run);
				obj.setWicket(wicket);
				obj.setMatches(matches);
				return true;
			}
			else
			p=p->getNext();
		}
		return false;
	}
}
void LinkedList::topThreePlayers(){
    if(start==NULL)
	{
		cout<<"\n No player in Liked List ";
	}
	else
	{
		int fmax,smax,tmax;
		fmax=smax=tmax=-999;
		
		Node *p1,*p2,*p3;
		p1=p2=p3=NULL;
		Node* p=start;
		cout<<"\n\n Player information \n";
		cout<<"\n___________________________________________________________________________";
		cout<<"\n|  JercyNO      |    Name     |   Runs    |  	Wicket    |  	Matches    |";
		cout<<"\n___________________________________________________________________________";
		while(p!=NULL)
		{
			if(fmax < p->getData().getRun())
			{
				tmax=smax;
				smax=fmax;
				fmax=p->getData().getRun();
				p3=p2;
				p2=p1;
				p1=p;
			}
			else if(smax < p->getData().getRun())
			{
				tmax=smax;
				smax=p->getData().getRun();
				p3=p2;
				p2=p;	
			}
			else if(tmax < p->getData().getRun())
			{
				tmax=p->getData().getRun();
				p3=p;
			}
			
			p=p->getNext();
		}
		
		p1->getData().displayPlayer();
		p2->getData().displayPlayer();
		p3->getData().displayPlayer();
	}
}
void LinkedList::readDataFromFile(const char * fileName)
{
    ifstream inFile(fileName, ios::binary);
    if (!inFile)
    {
        cout << "*Error*\nFile not opened";
        return;
    }
    Node* b;
    while(inFile.read((char* )(&b), sizeof(Node*)))
    {
        this->insertBeg(b);
    }
    inFile.close();
}

void LinkedList::writeDataToFile(const char *fileName)
{
    ofstream outFile;
	outFile.open(fileName, ios::binary );
    if (!outFile)
    {
        cout << "*Error*\nFile not Opened";
        return;
    }
    Node* p = start;
    while (p != NULL)
    {
        Player playerData = p->getData();
		outFile.write((char*)(&p->getData()),sizeof(Node*));
        p = p->getNext();
    }
    outFile.close();
}
LinkedList::~LinkedList(){
    ofstream out("demo.bin",ios_base::binary);
	while(start != NULL)
	{
		Node *p=start;
		out.write((char*)(&p->getData()),sizeof(p->getData()));
		start=start->getNext();
		delete p;	
	}
	out.close();
	cout<<"\n Liked List Desctructor called ";
}
Node::Node(Player& player){
    	this->player=player;
	    this->next=NULL;
}
void Node::setData(Player& player){
    this->player=player;
}
void Node::setNext(Node*){
    this->next=next;
}
Player& Node::getData(){
    return this->player;
}
Node* Node::getNext(){
    return this->next;
}

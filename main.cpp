#include"linklist.h"
using namespace std;

int main() {
	LinkedList lt;
	int choice=0;
	
	lt.readDataFromFile("player.txt");

	while(choice != 9)
	{
	     cout << "\n+--------------------------------------+\n"
                 "|           MENU OPTIONS               |\n"
                 "+--------------------------------------+\n"
                 "| 1) Add Player                        |\n"
                 "| 2) Search by jersey no               |\n"
                 "| 3) Delete Player                     |\n"
                 "| 4) Update Player runs                |\n"
                 "| 5) Update Player wickets             |\n"
                 "| 6) Update Player matches             |\n"
                 "| 7) Top 3 on runs                     |\n"
                 "| 8) Display Player                     |\n"
                 "| 9) Exit                               |\n"
                 "+--------------------------------------+\n"
                 "Enter your choice: ";
		cin>>choice;
			
		switch(choice)
		{
			case 1:{
				int j_no,runs,wickets,matches,pos;
				char name[20];
				cout<<"\nEnter jersey no :";
				cin>>j_no;
				cout<<"\nEnter name :";
				cin>>name;
				cout<<"\nEnter runs :";
				cin>>runs;
				cout<<"\nEnter wickets :";
				cin>>wickets;
				cout<<"\nEnter matches :";
				cin>>matches;
				cout<<"\nEnter Posotion :";
				cin>>pos;
				
				Player p1(j_no,name,runs,wickets,matches);
				lt.insertPos(p1,pos);
				break;
			}
			case 2:{
				int j_no;
				cout<<"\nEnter jersey no to search :";
				cin>>j_no;
				if(Node<Player> *p = lt.searchPlayer(j_no))
				{
					cout<<"\nPlayer is found...\n\n";
					p->getData().display();
				
				}
				else
				{
					cout<<"\nPlayer is not found\n";
				}
				break;
			}
			case 3:{
				int pos;
				cout<<"\nEnter position of player to delete :";
				cin>>pos;
				lt.deletePos(pos);
				break;
			}
			
			case 4:{
				int j_no,runs;
				cout<<"\nEnter jersey no to update runs :";
				cin>>j_no;
				cout<<"\nEnter new value of runs :";
				cin>>runs;
				if(lt.updateRuns(j_no,runs))
				{
					cout<<"\nPlayer runs updated successfully";
				}
				else
				{
					cout<<"\nPlayer not found";
				}
				break;
			}
			case 5:{
				int j_no,wicket;
				cout<<"\nEnter jersey no to update wickets :";
				cin>>j_no;
				cout<<"\nEnter new value of wickets :";
				cin>>wicket;
				if(lt.updateWickets(j_no,wicket))
				{
					cout<<"\nPlayer wickets updated successfully";
				}
				else
				{
					cout<<"\nPlayer not found";
				}
				break;
			}
			case 6:{
				int j_no, match;
				cout<<"\nEnter jersey no to update matches :";
				cin>>j_no;
				cout<<"\nEnter new value of matches :";
				cin>>match;
				if(lt.updateMatches(j_no,match))
				{
					cout<<"\nPlayer matches updated successfully";
				}
				else
				{
					cout<<"\nPlayer not found";
				}
				break;
			}
			case 7:{
				lt.top3PlayersByRuns();
				break;
			}
			case 8:{
				lt.display();
				break;
			}	
			case 9:{
				cout<<"\nExiting....";
				break;
			}
			default:{
				
				break;
			}
		}
	}	
	
	lt.writeDataToFile("player.txt");
	return 0;
	
}

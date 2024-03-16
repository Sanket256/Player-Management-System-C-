#include "LinkedList.cpp"
#include <fstream>
using namespace std;

int main()
{
    LinkedList lt;
    int choice = 0;
    ofstream hout("players.txt", ios::app);  
    ifstream hin("players.txt"); 

    do {
        cout << "+______________________________________+\n"
             << "|           MENU OPTIONS               |\n"
             << "+______________________________________+\n"
             << "| 1) Add Player                        |\n"
             << "| 2) Search by jersey no               |\n"
             << "| 4) Delete Player                     |\n"
             << "| 5) Update Player runs                |\n"
             << "| 6) Update Player wickets             |\n"
             << "| 7) Update Player matches             |\n"
             << "| 8) Top 3 on runs                     |\n"
             << "| 9) Top 3 on wickets                  |\n"
             << "|10) Display Player                    |\n"
             << "|11) Exit                              |\n"
             << "+______________________________________+\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int JerseyNo;
                cout << "\nEnter the jersey no: ";
                cin >> JerseyNo;

                char name[20];
                cout << "\nEnter the name: ";
                cin >> name;

                int run;
                cout << "\nEnter the run: ";
                cin >> run;

                int wicket;
                cout << "\nEnter the wicket: ";
                cin >> wicket;

                int matches;
                cout << "\nEnter the matches: ";
                cin >> matches;

                int pos;
                cout << "\nEnter the position to add player: ";
                cin >> pos;

                Player p1(JerseyNo, name, run, wicket, matches);
                lt.addPlayerToPosition(p1, pos);

                break;
            }
            case 2: {
                int pos;
                cout << "\nEnter the position to delete player: ";
                cin >> pos;
                lt.DeletePalyerFromPosition(pos);
                break;
            }
            case 3: 
                lt.displayInfo();
                break;
            case 4: {
                int jno;
                cout << "\nEnter the jersey no to search player: ";
                cin >> jno;
                if (lt.searchPlayer(jno))
                    cout << "\nFound !!!";
                else
                    cout << "\nNot found !!!";
                break;
            }
            case 5: {
                int jno;
                cout << "\nEnter the jersey no to update player: ";
                cin >> jno;
                if (lt.updatePlayer(jno))
                    cout << "\nUpdated Successfully !!!";
                else
                    cout << "\nNot found !!!";
                break;
            }
            case 6: {
                lt.topThreePlayers();
                break;
            }
            case 7: {
                if (!hin.is_open()) {
                    cout << "Error opening file." << endl;
                    return 1;
                }
                lt.readDataFromFile("players.txt");
                hin.close();
                break;
            }
            case 8: 
                cout << "\nExit Program ";
                return 0;
            default:
                cout << "\n\nInvalid choice ";
                break;
        }
    } while (choice != 8);

    return 0;
}

#include"player.h"
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
	Player::Player(){
        this->jerSeyNo=0;
        strcpy(this->name,"Name not given");
        this->runs=0;
        this->wickets=0;
        this->matches=0;
    }
	Player::Player(int v1,char* v2,int v3,int v4,int v5){
        this->jerSeyNo= v1;
        strcpy(this->name,v2);
        this->runs=v3;
        this->wickets=v4;
        this->matches=v5;
    }

	int Player::getJno(){
        return this->jerSeyNo;
    }
	char* Player::getName(){
        return this->name;
    }
	int Player::getRun(){
        return this->runs;
    }
	int Player::getWicket(){
        return this->wickets;
    }
	int Player::getMatches(){
        return this->matches;
    }

	void Player::setJno(int v1){
         this->jerSeyNo= v1;
    }
	void Player::setName(char* v2){
        strcpy(this->name,v2);
    }
	void Player::setRun(int v3){
         this->runs=v3;
    }
	void Player::setWicket(int v4){
        this->wickets=v4;
    }
	void Player::setMatches(int v5){
        this->matches=v5;
    }

	void Player::displayPlayer() {
    std::cout << "+_______________________________________+\n"
                 "|            PLAYER INFORMATION         |\n"
                 "+_______________________________________+\n"
                 "| Jersey No        | " << jerSeyNo << "\n"
                 "| Name             | " << name << "\n"
                 "| Runs             | " << runs << "\n"
                 "| Matches Played   | " << matches << "\n"
                 "| Wickets          | " << wickets << "\n"
                 "+_______________________________________+\n";
}
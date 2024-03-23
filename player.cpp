#include "player.h"
#include <iomanip>

Player::Player()
{
	j_no=0;
	strcpy(name,"Not given");
	runs=0;
	matches=0;
	wickets=0;
}
/////////////////////////////////////////////
Player::Player(int j ,char* nm, int r,int m, int w)
{
	j_no=j;
	strcpy(name,nm);
	runs=r;
	matches=m;
	wickets=w;
}
//////////////////////////////////////////////////
void Player::setJ_no(int j)
{
	j_no=j;
}
////////////////////////////////////////////
void Player::setName(char* nm)
{
	strcpy(name,"nm");
}
////////////////////////////////////////////
void Player::setRuns(int r)
{
	runs=r;
}
///////////////////////////////////////
void Player::setMatches(int m)
{
	matches=m;
}
///////////////////////////////////////////
void Player::setWicket(int w)
{
	wickets=w;
}
//////////////////////////////////////////
int Player::getJ_no()
{
	return j_no;
}
///////////////////////////////////////////////
char* Player::getName()
{
	return name;
}
////////////////////////////////////////////
int Player::getRuns()
{
	return runs;
}
///////////////////////////////////////////
int Player::getMatches()
{
	return matches;
}
//////////////////////////////////////
int Player::getWickets()
{
	return wickets;
}
//////////////////////////////////////////
void Player::display()
{ 
	cout<<"|"<<setw(14)<<j_no<<"|"<<setw(14)<<name<<"|"<<setw(14)<<runs<<"|"
			<<setw(16)<<matches<<"|"<<setw(14)<<wickets<<"|"<<"\n";
}

#include<iostream>
using namespace std;
#include"player.h"
template<class T>
 
class Node
{
	T data;
 	Node* next;
 	
 	public:
 		Node(T&);
 		T& getData();
 		Node* getNext();
		void setData(T&);
		void setNext(Node* ); 
};

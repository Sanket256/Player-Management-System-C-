#include"player.cpp"
class Node{

    Player player;
    Node* next;

    public:

    Node(Player&);
    void setData(Player&);
    void setNext(Node*);
    Player& getData();
    Node* getNext();
};
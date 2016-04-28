#include<iostream>
#include<memory>
#include<assert.h>
#include<initializer_list>

using namespace std;

class BT
{
public:
    struct Node
    {
        int value;
        shared_ptr<Node> lc;
        shared_ptr<Node> rc;

        Node(int v):value(v), lc(nullptr), rc(nullptr){}
        friend ostream& operator<<(ostream& os, shared_ptr<Node> n);
    };
private:
    shared_ptr<Node> root;

public:
    BT(std::initializer_list<int> l);
    shared_ptr<BT::Node> AddNode(std::initializer_list<int> l, uint index);
    shared_ptr<Node> Root(){return root;}
    friend ostream& operator<<(ostream& os, const BT & bt);
};

void print(ostream& os, shared_ptr<BT::Node> n);

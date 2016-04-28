#include<iostream>
#include<memory>
#include<assert.h>
using namespace std;

class BT
{
public:
    struct Node
    {
        int value;
        unique_ptr<Node> lc;
        unique_ptr<Node> rc;

        Node(int v):value(v), lc(nullptr), rc(nullptr){}
        friend ostream& operator<<(ostream& os, const unique_ptr<Node> & n);
    };
private:
    unique_ptr<Node> root;

public:
    void Add(int v);
    const unique_ptr<Node> & Root(){return root;}
    friend ostream& operator<<(ostream& os, const BT & bt);
private:
    void Add(unique_ptr<Node> & n, int v);
};

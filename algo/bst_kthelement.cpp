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

void BT::Add(int v)
{
    if(root.get()==nullptr)
    {
        root = make_unique<Node>(v);
    }
    else
    {
        Add(root,v);
    }

}

void BT::Add(unique_ptr<Node> & n, int v)
{
    assert(n.get() !=nullptr);

    if(n->value == v)
        return;

    if(n->value > v)
    {
        if(n->lc)
            Add(n->lc,v);
        else
            n->lc = make_unique<Node>(v);
    }
    else //if(n->value < v)
    {
        if(n->rc)
            Add(n->rc,v);
        else
            n->rc = make_unique<Node>(v);
    }
}

ostream& operator<<(ostream& os, const BT & bt)
{
    os << bt.root;
    return os;
}
ostream& operator<<(ostream& os, const unique_ptr<BT::Node> & n)
{
    if(n->lc)
        os<<n->lc<<",";
    os<<n->value;
    if(n->rc)
        os<<","<<n->rc;

    return os;
}

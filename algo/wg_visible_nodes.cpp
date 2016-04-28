//get the number of visible nodes in a binary tree

#include<iostream>
#include<memory>
#include<assert.h>
#include<initializer_list>
#include<queue>

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

BT::BT(std::initializer_list<int> l)
{
    root=AddNode(l,0);
}

shared_ptr<BT::Node> BT::AddNode(std::initializer_list<int> l, uint index)
{
    assert(index<l.size());

    auto it=l.begin();
    uint i=0;
    while(i<index) ++it,++i;

    shared_ptr<Node> n = make_shared<Node>(*it);

    auto leftchildindex= (index << 1) + 1;
    auto rightchildindex=leftchildindex+1;

    if(leftchildindex<l.size())
    {
        n->lc=AddNode(l, leftchildindex);
    }
    if(rightchildindex<l.size())
    {
        n->rc=AddNode(l, rightchildindex);
    }
    return n;
}

ostream& operator<<(ostream& os, const BT & bt)
{
    os << bt.root;
    return os;
}
ostream& operator<<(ostream& os, shared_ptr<BT::Node> n)
{
    queue<shared_ptr<BT::Node> > q;
    q.push(n);

    int i=0;
    while(!q.empty())
    {
        shared_ptr<BT::Node> n = q.front(); q.pop();

        if(i++ == 0)
            cout<<n->value;
        else
            cout<<","<<n->value;

        if(n->lc)
            q.push(n->lc);
        if(n->rc)
            q.push(n->rc);
    }

    return os;
}

int GetNbrOfVisible(shared_ptr<BT::Node> node, int largest_nbr)
{
    if(node.get()==nullptr)
        return 0;

    int i=0;

    if(node->value > largest_nbr)
    {
        largest_nbr=node->value;
        i=1;
    }

    return i+GetNbrOfVisible(node->lc, largest_nbr)+GetNbrOfVisible(node->rc, largest_nbr);
}

int GetNbrOfVisible(shared_ptr<BT::Node> node)
{
    int largest_nbr=-100000-1;

    return GetNbrOfVisible(node, largest_nbr);
}

int main()
{
    BT b{5,3,10,20,21,1,9};
    int nbrOfVisibles = GetNbrOfVisible(b.Root());
    cout << "nbrOfVisibles =" << nbrOfVisibles<<endl;

}

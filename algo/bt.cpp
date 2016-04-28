
#include "bt.h"
#include<queue>


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

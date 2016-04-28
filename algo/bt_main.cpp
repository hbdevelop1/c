
#include "bt.h"

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

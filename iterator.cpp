#include <iostream>
#include <deque>
#include <iterator>

using namespace std;
/*
create iterator for my list.
create an output iterator
an input iterator
a bidi iterator
a random one*/

namespace hassan
{
	template<class T>
	struct list
	{
		template <class Tv>
		struct node
		{
			Tv v;
			node<Tv>* next;
			
			node(Tv w):v(w), next(nullptr){}
		};
		
		struct node<T>* head;
		struct node<T>* last;
		unsigned int size;
		
	public:
		list():head(nullptr),last(nullptr), size(0)
		{
		}
		
		~list()
		{
			if(size==0)
				return;
				
			list<int>::node<int> *n = head;
			list<int>::node<int> *n2= n->next;
			for(uint i=0; i<size; ++i)
			{
				n2= n->next;
				delete n;
				n=n2;
			}
			head=last=nullptr;
			size=0;
			
		}
		void push_back(T);
		
	};
	
	template<class T>
	void list<T>::push_back(T v)
	{
		node<T> * n=new node<T>(v);
		n->next=nullptr;
		if(head)
		{
			last->next = n;
		}	
		else
		{
			head = n;
		}
		last = n;
		
		++size;
	}
	

}

int main()
{
	
	hassan::list<int> li;

	auto print=[&]()
	{
		hassan::list<int>::node<int> *n = li.head;
		for(uint i=0; i<li.size; ++i)
		{
			cout << n->v << ",";
			n=n->next;
		}
		cout << "\n";
	};	

	li.push_back(4);
	li.push_back(19);

	print();
	
	return 0;
}

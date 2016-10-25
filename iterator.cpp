#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;
/*
create iterator for my list.
create an output iterator
an input iterator (done. proof is it is being used by find)
a bidi iterator
a random one*/

namespace hassan
{
	template<class T>
	struct list
	{
		struct node_base
		{
			node_base* next;
			node_base(node_base* p):next(p){}
		};
		
		template <class Tv>
		struct node : public node_base
		{
			Tv data;
			node(node_base* n,Tv w):node_base(n),data(w){}
		};
		
		node<unsigned int> m_impl;

	public:
	/*
	//1-either define :
		struct iterator
		{
			typedef std::forward_iterator_tag    iterator_category;
			typedef ptrdiff_t                          difference_type;
			typedef T                                value_type;
			typedef T*                               pointer;
			typedef T&                               reference;
			 
		};
		//2-define 
		typedef std::iterator<std::forward_iterator_tag, T, ptrdiff_t, T*, T&>  iterator;
		 */
		 
		/*
		 * 1-
		struct iterator
		{
			 
		};
		  
		hassan::list<int>::iterator itr = std::find (ite, itb, 30);
		 
		In file included from /usr/include/c++/5/algorithm:62:0,
                 from iterator.cpp:4:
/usr/include/c++/5/bits/stl_algo.h: In instantiation of ‘_Iterator std::__find_if(_Iterator, _Iterator, _Predicate) [with _Iterator = hassan::list<int>::iterator; _Predicate = __gnu_cxx::__ops::_Iter_equals_val<const int>]’:
/usr/include/c++/5/bits/stl_algo.h:3790:28:   required from ‘_IIter std::find(_IIter, _IIter, const _Tp&) [with _IIter = hassan::list<int>::iterator; _Tp = int]’
iterator.cpp:146:59:   required from here
/usr/include/c++/5/bits/stl_algo.h:162:34: error: no matching function for call to ‘__iterator_category(hassan::list<int>::iterator&)’
          std::__iterator_category(__first));
                                  ^
In file included from /usr/include/c++/5/bits/stl_algobase.h:65:0,
                 from /usr/include/c++/5/bits/char_traits.h:39,
                 from /usr/include/c++/5/ios:40,
                 from /usr/include/c++/5/ostream:38,
                 from /usr/include/c++/5/iostream:39,
                 from iterator.cpp:1:
/usr/include/c++/5/bits/stl_iterator_base_types.h:204:5: note: candidate: template<class _Iter> typename std::iterator_traits<_Iterator>::iterator_category std::__iterator_category(const _Iter&)
     __iterator_category(const _Iter&)
*/

/*     2--
		struct iterator
		{
			 
		};

	typename std::iterator_traits<hassan::list<int>::iterator>::iterator_category ic;

iterator.cpp:169:62: error: ‘iterator_category’ in ‘struct std::iterator_traits<hassan::list<int>::iterator>’ does not name a type
  typename std::iterator_traits<hassan::list<int>::iterator>::iterator_category ic;
                                                                                ^

 * solution 1
		struct iterator
		{
			typedef std::forward_iterator_tag    iterator_category;
			typedef ptrdiff_t                          difference_type;
			typedef T                                value_type;
			typedef T*                               pointer;
			typedef T&                               reference;
			 
		};
 * 
 * solution 2
	reuse std::iterator
	typedef std::iterator<std::forward_iterator_tag, T, ptrdiff_t, T*, T&>  iterator;
 * 
 * 
 * 
 * */
 /*
	typedef std::iterator<std::forward_iterator_tag, T, ptrdiff_t, T*, T&>  iterator;
	...
 	hassan::list<int>::iterator itr = std::find (ite, itb, 30);

In file included from /usr/include/c++/5/algorithm:62:0,
                 from iterator.cpp:4:
/usr/include/c++/5/bits/stl_algo.h: In instantiation of ‘_InputIterator std::__find_if(_InputIterator, _InputIterator, _Predicate, std::input_iterator_tag) [with _InputIterator = std::iterator<std::forward_iterator_tag, int, long int, int*, int&>; _Predicate = __gnu_cxx::__ops::_Iter_equals_val<const int>]’:
/usr/include/c++/5/bits/stl_algo.h:161:23:   required from ‘_Iterator std::__find_if(_Iterator, _Iterator, _Predicate) [with _Iterator = std::iterator<std::forward_iterator_tag, int, long int, int*, int&>; _Predicate = __gnu_cxx::__ops::_Iter_equals_val<const int>]’
/usr/include/c++/5/bits/stl_algo.h:3790:28:   required from ‘_IIter std::find(_IIter, _IIter, const _Tp&) [with _IIter = std::iterator<std::forward_iterator_tag, int, long int, int*, int&>; _Tp = int]’
iterator.cpp:203:59:   required from here
/usr/include/c++/5/bits/stl_algo.h:104:22: error: no match for ‘operator!=’ (operand types are ‘std::iterator<std::forward_iterator_tag, int, long int, int*, int&>’ and ‘std::iterator<std::forward_iterator_tag, int, long int, int*, int&>’)
       while (__first != __last && !__pred(__first))
                      ^

	*/
	
//to make it forward, uncomment the line:
//		struct iterator : public std::iterator<std::forward_iterator_tag, T, ptrdiff_t, T*, T&>
		struct iterator : public std::iterator<std::input_iterator_tag, T, ptrdiff_t, T*, T&>
		{
			node_base *index;
			
			iterator(node_base * n ):index(n)
			{
			}
			
			bool operator!=(const iterator & i2)
			{
				return index != i2.index;
			}
			T operator*()
			{
				return static_cast<node<T>*>(index)->data;
			}
			void operator++()
			{
				index=index->next;
			}
		};
		
		iterator begin()
		{
			return iterator(m_impl.next);
		}
		iterator end()
		{
			return iterator(&m_impl);
		}
		
	public:
		list():m_impl(&m_impl,0)
		{
		}
		
		~list();
		void push_back(T);
		
	};
	
	template<class T>
	list<T>::~list()
	{
		if(m_impl.data==0)
			return;
			
		node_base *e=m_impl.next;
		while(e != &m_impl)
		{
			m_impl.next=e->next;
			delete e;
			e=m_impl.next;
		}
	}
	
	template<class T>
	void list<T>::push_back(T v)
	{
		node_base *e=&m_impl;
		//find the last element; a better solution would be to have prev pointer
		while(e->next != &m_impl)
		{
			e=e->next;
		}

		node<T> * n=new node<T>(&m_impl, v);
		
		e->next = n;
		++m_impl.data;
	}
	

}

int main()
{
	hassan::list<int> li;
	
	li.push_back(221);
	li.push_back(222);
	li.push_back(223);
	li.push_back(224);
	li.push_back(225);
	li.push_back(226);
	li.push_back(227);
	li.push_back(228);
	li.push_back(229);
	li.push_back(230);
	
	hassan::list<int>::iterator it =li.begin();
	hassan::list<int>::iterator ite =li.end();
	for(;it!=ite; ++it)
	{
		printf("%d\n",*it);
	}
	
	hassan::list<int>::iterator itb =li.begin();
	int to_find=226;
	hassan::list<int>::iterator itr = std::find (itb, ite, to_find);
	hassan::list<int>::iterator::difference_type d = std::distance(itb,itr);
	printf("%d is found %d spots from the begining\n",to_find,d);
	//hassan::list<int>::iterator itr2 = std::find (ite, itb, 30);
	
	return 0;
}
#if 0
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
	
	hassan::list<int>::iterator itb =li.begin();
	hassan::list<int>::iterator ite =li.end();
	
	
	
	//typename std::iterator_traits<hassan::list<int>::iterator>::iterator_category ic;
	//typename std::iterator_traits<std::iteratorhassan>::iterator_category ic2;

	hassan::list<int>::iterator itr = std::find (ite, itb, 30);
	//typename hassan::list<int>::iterator::iterator_category ic3;
	return 0;
}
#endif
#if 0
  iterator
      begin() _GLIBCXX_NOEXCEPT
      { return iterator(this->_M_impl._M_node._M_next); }

      /**
       *  Returns a read-only (constant) iterator that points to the
       *  first element in the %list.  Iteration is done in ordinary
       *  element order.
       */
      const_iterator
      begin() const _GLIBCXX_NOEXCEPT
      { return const_iterator(this->_M_impl._M_node._M_next); }

      /**
       *  Returns a read/write iterator that points one past the last
       *  element in the %list.  Iteration is done in ordinary element
       *  order.
       */
      iterator
      end() _GLIBCXX_NOEXCEPT
      { return iterator(&this->_M_impl._M_node); }
	  
      void
      push_back(const value_type& __x)
      { this->_M_insert(end(), __x); }

     template<typename... _Args>
       void
       _M_insert(iterator __position, _Args&&... __args)
       {
	 _Node* __tmp = _M_create_node(std::forward<_Args>(__args)...);
	 __tmp->_M_hook(__position._M_node);
	 this->_M_inc_size(1);
       }	  
$3 = {
  <std::__cxx11::_List_base<int, std::allocator<int> >> = 
  {
    _M_impl = 
	{
      <std::allocator<std::_List_node<int> >> = 
	  {
        <__gnu_cxx::new_allocator<std::_List_node<int> >> = {<No data fields>}, <No data fields>
	  }, 
      members of std::__cxx11::_List_base<int, std::allocator<int> >::_List_impl: _M_node = 
	  {
        <std::__detail::_List_node_base> = 
		{
          _M_next = 0x7fffffffde00, 
          _M_prev = 0x7fffffffde00
        }, 
        members of std::_List_node<unsigned long>:_M_data = 0
      }
    }
  }, <No data fields>}
(gdb) 


  /// An actual node in the %list.
  template<typename _Tp>
    struct _List_node : public __detail::_List_node_base
    {
      ///< User's data.
      _Tp _M_data;

#if __cplusplus >= 201103L
      template<typename... _Args>
        _List_node(_Args&&... __args)
	: __detail::_List_node_base(), _M_data(std::forward<_Args>(__args)...) 
        { }
#endif
    };
#endif
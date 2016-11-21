//leading chars are moved towards the tail (using to_tail), and vice versa (using to_head)
//the algo: each character ends up moved to a new index. index depends on the length of the substring

//question 27

#include <iostream>
#include <string>
#include <string.h>
#include <assert.h>

using namespace std;

struct StringRotator
{
	string 				s;
	int 				s_l;
	int					ss_l;
	int					nbr_of_chars_to_move;

	/*
	 * char *s: string to rotate
	 * int s_l: length of string to rotate;
	 * int ss_l:length of the substring
	 * int i:index in the string to the char to move to tail ('a' ? 'b' ? , ...)
	 * */

	void move(int i0, int v0)
	{
		//??????? if(i0>=s_l-1) //i does't point to a valid char
		if(i0>=s_l) //i does't point to a valid char
			return;
			
		if(i0<0) //i does't point to a valid char
			return;
		
		int i1;
		
		if(i0 < ss_l) 
			i1=s_l-ss_l+i0; //we're moving the char towards the tail
		else
			i1 = i0 - ss_l; //we're moving the char towards the head

		int v1 = s[i1];
		s[i1]=v0;
		
		--nbr_of_chars_to_move;
		
		if(nbr_of_chars_to_move>0)
			move(i1,v1);
	}
public:
	StringRotator(string str):s(str)
	{
		s_l=s.length();
		nbr_of_chars_to_move=s_l;
	}
	void Rotate(int ssl)
	{
		if(ssl>=s_l || ssl<1)
			return;
			
		ss_l=ssl;
		move(0,s[0]);
	}
};


void test_rotate_string2(string s, int ssl, const string & control)
{
	StringRotator sr(s);
	sr.Rotate(ssl);
	assert(sr.s==control);
	cout<<"success: "<<s<< ","<<ssl<<endl;
}

int main()
{
	char str[]="abcdefg";

	test_rotate_string2(str, 1, "bcdefga");
	test_rotate_string2(str, 2, "cdefgab");
	test_rotate_string2(str, 5, "fgabcde");
	test_rotate_string2(str, 10, "abcdefg");
	test_rotate_string2(str, 0, "abcdefg");
	test_rotate_string2(str, -1, "abcdefg");
	
return 0;
}
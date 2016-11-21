//leading chars are moved towards the tail (using to_tail), and vice versa (using to_head)
//the algo: each character ends up moved to a new index. index depends on the length of the substring

#include <iostream>
#include <string>
#include <memory>
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
	void to_tail(int i0, int v0)
	{
		if(i0>=s_l-1) //i does't point to a valid char
			return;
			
		if(i0<0) //i does't point to a valid char
			return;
		
		int i1=s_l-ss_l+i0;
		int v1 = s[i1];
		s[i1]=v0;
		
		--nbr_of_chars_to_move;
		
		if(nbr_of_chars_to_move>0)
			to_head(i1,v1);
	}

	void to_head(int i0, int v0)
	{
		if(i0<=0)
			return;
			
		if(i0>=s_l) //i does't point to a valid char
			return;

		int i1 = i0 - ss_l;
		int v1=s[i1];
		s[i1]=v0;
		
		--nbr_of_chars_to_move;
		
		if(nbr_of_chars_to_move>0)
			to_tail(i1, v1);
	}

	void move(int i0, int v0)
	{
		if(i0>=s_l-1) //i does't point to a valid char
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
		nbr_of_chars_to_move=s.length();
	}
	void Rotate(int ssl)
	{
		ss_l=ssl;
		//to_tail(0,s[0]);
		move(0,s[0]);
	}
};


//rotate_string and return unique_ptr on result
unique_ptr<char> rotate_string2(string str, int i)
{
	int l = str.length();
	if(i >= l) //nothing to rotate
		return unique_ptr<char>();
		
	//char *s=str.c_str();
	unique_ptr<char> ptr(new char[str.length()+1]);
	memcpy(ptr.get(), str.c_str(), str.length()+1);
	
	
	rotate_advance(ptr.get(), str.length(), i);
	
	return ptr;
}

//rotate_string and print result
void rotate_string1(string str, int i)
{
	//char *s=str.c_str();
	shared_ptr<char> ptr(new char[str.length()+1]);
	memcpy(ptr.get(), str.c_str(), str.length()+1);
	printf("%s\n", ptr.get());
}

void test_rotate_string2(string s, int ssl, const string & control)
{
	StringRotator sr(s);
	sr.Rotate(ssl);
	assert(sr==control);
}

int main()
{
	char str[]="abcdefg";

	test_rotate_string2(str, 1, "bcdefga");
	test_rotate_string2(str, 2, "cdefgab");
	test_rotate_string2(str, 5, "fgabcde");
	test_rotate_string2(str, 10, "bcdefga");
	test_rotate_string2(str, 0, "abcdefg");
	test_rotate_string2(str, -1, "bcdefga");
	
return 0;

	unique_ptr<char> result;
	for(int i=0, l=strlen(str); i<l; ++i)
	{
		result=rotate_string2(str, i);
		printf("rotating %s by %d: %s\n", str,i, result.get());
	}

return 0;
	for(int i=0, l=strlen(str); i<l; ++i)
	{
		printf("rotating %s by %d:", str,i);
		rotate_string1(str, i);
	}

	
	return 0;
}
#include <iostream>
#include <functional>
#include <list>

using namespace std;

std::list<std::function<bool(char)> > expected_functions;

bool expect_digit = false;
bool expect_dot = false;
bool expect_sign = false;

namespace hb
{
bool dot(char c)
{
	bool dot_found = (c=='.');

	if(dot_found)
	{
		expect_dot = false;  //dot encountered. don't expect it any more.
		expect_sign = false; //remove the possiblity to accept a sign, now that we 've encountered a dot 
	}

	return dot_found;
}

bool sign(char c)
{
	bool sign_found = (c=='+' || c=='-');
	if(sign_found)
		expect_sign=false;

	return sign_found;
}

bool digit(char c)
{
	bool digit_found = (isdigit(c)!=0);
	if(expect_sign && digit_found) //remove the possiblity to accept a sign, now that we 've encountered a digit 
		expect_sign = false;
	return digit_found;
}
} //hb

bool doesCharacterMatchExpected(char *p)
{
	char c = *p;
	for(auto fn : expected_functions)
		if(fn(c))
			return true;
	return false;	
}

bool lexical_analysis_conforms(char *str)
{
	int i=0;

	expect_dot = true;
	expect_digit=true;
	expect_sign =true;

	while(str[i])
	{
		if(i==0)
		{
			expected_functions.clear();

			if(expect_sign) 	expected_functions.push_back(hb::sign);
			if(expect_digit)	expected_functions.push_back(hb::digit);
			if(expect_dot) 		expected_functions.push_back(hb::dot);
		}
		else
		{
			expected_functions.clear();

			if(expect_digit)	expected_functions.push_back(hb::digit);
			if(expect_dot) 		expected_functions.push_back(hb::dot);
		}
		if(!doesCharacterMatchExpected(&str[i]))
			return false;

		++i;
	}
	return true;
}


int main(int arc, char** argv)
{
	if(arc != 2)
	{
		cout <<"enter a string to analyze." << endl;
		return -1;
	}

	char *str=argv[1];

	bool f = lexical_analysis_conforms(str);

	f? cout << str << " conforms to lexic" << endl
	 : cout << str << " does't conform to lexic" << endl;

	return 0;
}
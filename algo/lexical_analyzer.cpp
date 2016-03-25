#include <iostream>
#include <functional>
#include <list>

using namespace std;

std::list<std::function<bool(char)> > expected_functions;

namespace hb
{
bool dot(char c)
{
	return (c=='.');
}

bool sign(char c)
{
	return (c=='+' || c=='-');
}

bool digit(char c)
{
	return isdigit(c)!=0;
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
	while(*str)
	{
		if(!doesCharacterMatchExpected(str))
			return false;

		++str;
	}
	return true;
}


int main()
{
	char str[]="+1";

	expected_functions.clear();
	expected_functions.push_back(hb::sign);
	expected_functions.push_back(hb::digit);
	expected_functions.push_back(hb::dot);

	lexical_analysis_conforms(str);

	return 0;
}
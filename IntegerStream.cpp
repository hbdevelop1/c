/*
IntegerStream is a class that, given an input stream containing ints, provides an iterator to read the valid integers found on valid ines in the stream.
Invalid ints are not exposed.
Please see main below for an example of usage.

Only valid numbers in the input stream are loaded.
For an int to be valid, it should be the only one on the line.
Spaces are allowed before and after the integer.
Invalid number include: 2u1, 23.4, #12, ++1 and any number not in the range [-1000000000, 1000000000]

for a stream containing the following:
"
 23.9
 2000000000 

  +0
 ++3 
+1 
 -0 
five
 -1
 137
	-104
2 58"

IntegerStream will expose the its iterator only the following intergers: 0, 1, 0 -1 137, -104

IntegerStream loads the integers from the file using a finite state machine like solution. This makes parsing the file very robust, maintainable and easily extendable.
each state is handled by one function, hence the following functions/states in the class

State1LookForDigit();  	//to move in the stream looking for a first digit
State2ReadDigit();		//we get here from State1LookForDigit. In this state, the stream reads the digits.
State3ReadSpaceOnly();	//we get here from State2ReadDigit. In this state, the stream makes sure the line after the integer remains valid until the end of line
State4IgnoreCurrentLine(); //We get here when the line is invalid and we need to move on to the next line.

*/



#include <iostream>
#include <fstream>
#include <vector>
#include <assert.h>
using namespace std;

class IntegerStream
{
	istream & 			m_s;
	char * 				m_content ;
	int 				m_size;
	char * 				m_reader;
	vector<int> 		m_v;
	bool 				m_signed;
	
	const static int 	max_size=10;
	const static int 	max_int_value=1000000000;
	char 				m_number[max_size+1];
	int 				m_number_size=0;

	void (IntegerStream::*m_state)();
	
private:
	void AnalyzeAndLoad();
	void State1LookForDigit();//: look for digit
	void State2ReadDigit();
	void State3ReadSpaceOnly();
	void State4IgnoreCurrentLine();
	void PushNumber();

private:
	bool isEof()
	{
		return (m_reader==m_content+m_size);
	}
	bool isSpace(char *p)
	{
		return (*p == ' ' || *p == '\t');
	}
public:	
	class iterator
	{
		vector<int>::iterator m_it;

	public:
		iterator(vector<int>::iterator it):m_it(it)
		{
		}
		int operator*();
		bool operator!=(iterator it);
		void operator++();
	};
	
public:
	IntegerStream(istream &s);
	~IntegerStream();
	
	iterator begin();
	iterator end();
	
};

IntegerStream::IntegerStream(istream &s):m_s(s)
{
	m_s.seekg (0, m_s.end);
    m_size = m_s.tellg();
    m_s.seekg (0, m_s.beg);
    m_content = new char [m_size];
    m_s.read (m_content,m_size);

	m_reader= m_content;
	AnalyzeAndLoad();
}

void IntegerStream::AnalyzeAndLoad()
{
	//state1: look for digit;
	m_state = State1LookForDigit;
	while(!isEof())
	{
		(this->*m_state)();
	}
	
	if(m_state == &State2ReadDigit || m_state == &State3ReadSpaceOnly) //we found an eof while reading a digit, push it
	{
		PushNumber();
	}
}

/*
state1: look for digit
{
	if (space) move;
	if (endoffile) end;
	if (+ or -) move and state2:read digit
	if (digit) state2:read digit
	else state4:move to next line;
}

state2:read digit
{
	if (space) state3:read space or eof;
	if (digit) push digit;
	if (endoffile) end;
	else state4:move to next line;
}

state3:read space or eof
{
	if (space) move;
	if (endoffile) end;
	else drop digit and state4:move to next line;
}

state4:move to next line IgnoreCurrentLine
{
	if(10) move and state1: look for digit;
	if (endoffile) end;
	else move;
}
*/

void IntegerStream::State1LookForDigit()//: look for digit
{
	if(isSpace(m_reader))
	{
		++m_reader;
	}
	else if(*m_reader == '+' || *m_reader == '-')
	{
		m_state = State2ReadDigit;  m_number_size=0; 
		m_signed = (*m_reader == '-');
		++m_reader;
	}
	else if(*m_reader>= '0' && *m_reader<= '9')
	{
		m_state = State2ReadDigit;  m_number_size=0;
	}
	else
	{
		m_state = State4IgnoreCurrentLine;
	}		
}

void IntegerStream::State2ReadDigit()
{
	//if get here, we have found a digit in State1LookForDigit but we haven't consumed it yet.
	if(isSpace(m_reader) || *m_reader == 13)
	{
		++m_reader;
		m_state = State3ReadSpaceOnly;//state3:read space or eof;
	}
	else if(*m_reader>= '0' && *m_reader<= '9')
	{
		if(m_number_size>=max_size)
		{
			m_state = State4IgnoreCurrentLine;
		}
		else
		{
			m_number[m_number_size++]=*m_reader;			
			m_reader++;
		}
	}
	else if(*m_reader == 10)
	{
		PushNumber();
		
		++m_reader;
		m_state=State1LookForDigit;
	}
	else
	{
		m_number_size=0;
		m_state = State4IgnoreCurrentLine;
	}
}

void IntegerStream::State3ReadSpaceOnly()// state3:read space or eof
{
	if(isSpace(m_reader) || *m_reader == 13 )
	{
		++m_reader;
	}
	else if(*m_reader == 10)
	{
		PushNumber();
		
		++m_reader;
		m_state=State1LookForDigit;
	}
	else
	{
		//ignore the number we read and move on to the next line
		m_number_size=0;
		m_state = State4IgnoreCurrentLine;
	}

}
void IntegerStream::State4IgnoreCurrentLine()
{
	//cout << "State4IgnoreCurrentLine"<<endl;

	if(*m_reader == 10)
	{
		++m_reader;
		
		m_state=State1LookForDigit;
	}
	else
	{
		++m_reader;		
	}
}

void IntegerStream::PushNumber()
{
	assert(m_number_size>0); //otherwise, how come we got here and m_number_size==0 ?
	m_number[m_number_size]=0;
	int i = atoi(m_number);
	if(i > max_int_value)
	{
		m_number_size=0;
		return;
	}
	
	if(m_signed)
		i *= -1;
	m_v.push_back(i);		
}

IntegerStream::~IntegerStream()
{
    delete m_content;
}

IntegerStream::iterator IntegerStream::begin()
{
	return iterator(m_v.begin());
}

IntegerStream::iterator IntegerStream::end()
{
	return iterator(m_v.end());
}

void IntegerStream::iterator::operator++()
{
	++m_it;
}
bool IntegerStream::iterator::operator!=(IntegerStream::iterator it)
{
	return (it.m_it != m_it);
}
int IntegerStream::iterator::operator*()
{
	return *m_it; 
}


int main()
{
	ifstream f("IntegerStream_test.txt");
	if(!f)
		return 1;
	
	IntegerStream so1(f);
	
	for(IntegerStream::iterator it = so1.begin(); it != so1.end(); ++it)
	{
		int x=*it;
		cout << x << endl;
	}
	
	return 0;
}

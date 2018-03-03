#ifndef Person_h
#define Person_h

#include "iostream"

using namespace std;

class Person
{
public:
	Person(string);					// initialise the name 
	virtual void printname() = 0;	
	bool operator<(const Person& p);

protected:
	string name;
};
#endif

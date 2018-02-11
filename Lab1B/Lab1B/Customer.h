#ifndef Customer_h
#define Customer_h

#include <iostream>
#include "Person.h"

using namespace std;

class Customer : public Person
{
public:
	Customer(string);
	void printname();
};
#endif

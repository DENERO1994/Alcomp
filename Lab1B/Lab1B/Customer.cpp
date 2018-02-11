#include <string>
#include <iostream>
#include "Customer.h"

Customer::Customer(string name) :Person(name){}

void Customer::printname()
{
	Person::printname();
	cout << " and I want to make a complaint";
}

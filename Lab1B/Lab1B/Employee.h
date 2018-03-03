#pragma once
#ifndef Employee_h
#define Employee_h

#include <iostream>
#include "Person.h"

using namespace std;

class Employee : public Person
{
public:
	Employee(string, double);
	void printname();
private:
	double salary;
};
#endif

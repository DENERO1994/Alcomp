#include <string>
#include <iostream>
#include "Person.h"

Person::Person(string Newname)
{
	name = Newname;
}

void Person::printname()
{
	cout << "\nMy name is " << name;
}

bool Person::operator<(const Person& person)
{
	if (person.name.compare(name) < 0) {
		return false;
	}
	else
	{
		return true;
	}
}
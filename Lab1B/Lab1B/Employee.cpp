#include "Employee.h"

Employee::Employee(string name, double salary) :Person(name), salary(salary){}

void Employee::printname()
{
	Person::printname();
	cout << " and my salary is " << salary;
}
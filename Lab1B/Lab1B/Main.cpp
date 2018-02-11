#include <iostream>
#include <algorithm>

#include "Person.h"
#include "Customer.h"
#include "Employee.h"
using namespace std;

int main()
{
	Person* personPtr;

	personPtr = new Employee("Barry", 1500);
	personPtr->printname();

	personPtr = new Customer("John");
	personPtr->printname();

	int const size = 3;
	Person* ptrs[size];

	Person* ptr1 = new Customer("Rob");
	Person* ptr2 = new Employee("Keith", 1200);
	Person* ptr3 = new Employee("Dave", 1600);

	ptrs[0] = ptr1;
	ptrs[1] = ptr2;
	ptrs[2] = ptr3;

	for (int i = 0; i < size; i++)
	{
		ptrs[i]->printname();
	}

	/***************************************************************************************
	*    Usage: modified
	*    Title: Beginners guide to the std::sort() function
	*    Date: 11/02/2018
	*    Availability: http://www.cplusplus.com/articles/NhA0RXSz/
	***************************************************************************************/

	std::sort(begin(ptrs), end(ptrs), [](Person* a, Person* b) { return *a < *b; });

	cout << "\n\nAfter sort";
	for (int i = 0; i < size; i++)
	{
		ptrs[i]->printname();
	}

	system("pause");
	return 0;
}
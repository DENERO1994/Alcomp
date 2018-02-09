#include "Software.h"
#include "Book.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	const int size = 7;
	Product *ptrs[size];

	Book *book1;
	Software *software1;

	double price;
	const char software = 's';
	const char book = 'b';
	char type;

	cout << "Enter price of book:";
	cin >> price;
	book1 = new Book(price);

	cout << "Enter price of Software:";
	cin >> price;
	software1 = new Software(price);

	ptrs[0] = book1;
	ptrs[1] = software1;

	for (int i = 2; i <= size; i++)
	{
		cout << "Enter price of item " << i + 1 << ": ";
		cin >> price;
		cout << "Is this a book or software (s/b): ";
		cin >> type;

		if (type == software)
		{
			ptrs[i] = new Software(price);
		}
		if (type == book)
		{
			ptrs[i] = new Book(price);
		}
	}

	for (int i = 0; i <= size; i++)
	{
		cout << ptrs[i]->getGrossPrice() << "\n";
	}

	sort(ptrs, ptrs + size);

	for (int i = 0; i <= size; i++)
	{
		cout << ptrs[i]->getGrossPrice() << "\n";
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

template <class T1> void swap(T1* lhs, T1* rhs)
{
	T1 temp;
	temp = *rhs;
	*rhs = *lhs;
	*lhs = temp;
}

template <class WhatKind> void multiples(WhatKind& sum, WhatKind x, int n)
{
	sum = 1;

	for (int i = 0; i <= n; i++)
	{
		sum += (i * x);
	}
}


template <class T1, class T2>
T1 init(T1 num1, T1 num2, T2& start)
{
	start = T2(1);
	return T1(num1 + num2);
}

/***************************************************************************************
*    Usage: modified
*    Title: QUICKSORT Quick sort with te,plate
*    Date: 11/02/2018
*    Availability: http://www.cplusplus.com/forum/beginner/119660/
***************************************************************************************/

template <typename T>
T* quicksort(T* array, int start, int end)
{
	int i = start, j = end;

	int temp;

	int pivot = array[(start + end) / 2];

	while (i <= j) {

		while (array[i] < pivot)

			i++;

		while (array[j] > pivot)

			j--;

		if (i <= j) {

			temp = array[i];

			array[i] = array[j];

			array[j] = temp;

			i++;
			j--;
		}

	};

	if (start < j)
	{
		quicksort(array, start, j);
	}

	if (i < end)
	{
		quicksort(array, i, end);
	}

	return array;
}


int main()
{
	//Q1
	int int1 = 7;
	int int2 = 16;

	float float1 = 16.3;
	float float2 = 45.1;

	swap(&int1, &int2);
	cout << "\nint1: " << int1 << "\nint2: " << int2;

	swap(&float1, &float2);
	cout << "\n\nfloat1: " << float1 << "\nfloat2: " << float2;


	//Q2
	int total;
	multiples(total, 10, 20);
	cout << "\n" << total;


	//Q3
	int int1 = 10;
	int int2 = 20;
	double start = 2.2;
	cout << "\n" << init(int1, int2, start);
	cout << start << "\n";


	//Q4
	int ints[] = {7, 8, 21, 100, 231, 500, 644};

	cout << "Before sorting: /n";
	for (int i = 0; i < 7; i++)
	{
		cout << ints[i] << endl;
	}

	quicksort(ints, 0, 6);
	cout << "\nAfter quick sorting";

	for (int i = 0; i < 7; i++)
	{
		cout << ints[i] << endl;
	}

	system("pause");
	return 0;
}
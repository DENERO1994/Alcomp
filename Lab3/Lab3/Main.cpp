#include "iostream"
#include "vector"

using namespace std;

/***************************************************************************************

*    Usage: modified
*    Title: Merge Sort
*    Author: cppnoob25
*    Date: 16/02/2018
*    Availability: http://www.cplusplus.com/forum/general/166536/
*
***************************************************************************************/

//void merge(int arraySortedInTwoHalves[], int startindex, int length)
//{
//	int size = (length - startindex) + 1;
//	int *b = new int[size]();
//
//	int i = startindex;
//	int mid = (startindex + length) / 2;
//	int k = 0;
//	int j = mid + 1;
//
//	while (k < size)
//	{
//		if ((i <= mid) && (arraySortedInTwoHalves[i] < arraySortedInTwoHalves[j]))
//		{
//			b[k++] = arraySortedInTwoHalves[i++];
//		}
//		else
//		{
//			b[k++] = arraySortedInTwoHalves[j++];
//		}
//
//	}
//
//	for (k = 0; k < size; k++)
//	{
//		arraySortedInTwoHalves[startindex + k] = b[k];
//	}
//
//	delete[]b;
//}
//
//void mergeSort(int arrayToSort[], int startindex, int lengthToSort)
//{
//	int midIndex;
//
//	if (startindex >= lengthToSort)
//	{
//		return;
//	}
//
//	midIndex = (startindex + lengthToSort) / 2;
//
//	mergeSort(arrayToSort, startindex, midIndex);
//	mergeSort(arrayToSort, midIndex + 1, lengthToSort);
//	merge(arrayToSort, startindex, lengthToSort);
//}

/***************************************************************************************

*    Usage: modified
*    Title: QuickSort
*    Author: GeeksforGeeks
*    Date: 19/02/2018
*    Availability: https://www.geeksforgeeks.org/quick-sort/
*
***************************************************************************************/

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int quickSortDivide(int theArray[], int first, int last)
{
	int pivot = theArray[last];
	int i = (first - 1);

	for (int j = first; j <= last - 1; j++)
	{
		if (theArray[j] <= pivot)
		{
			i++;
			swap(&theArray[i], &theArray[j]);
		}
	}
	swap(&theArray[i + 1], &theArray[last]);
	return (i + 1);
}

void quickSort(int theArray[], int first, int last)
{
	if (first < last)
	{
		int pi = quickSortDivide(theArray, first, last);

		quickSort(theArray, first, pi - 1);
		quickSort(theArray, pi + 1, last);
	}
}

int main()
{
	int unsortedArray[4] = { 3,2,1,9 };

	for (int i = 0; i < 4; i++)
	{
		cout << unsortedArray[i] << " ";
	}

	cout << "\n\n";
	quickSort(unsortedArray, 0, 3);

	for (int i = 0; i < 4; i++)
	{
		cout << unsortedArray[i] << " ";
	}

	system("pause");
	return 0;
}
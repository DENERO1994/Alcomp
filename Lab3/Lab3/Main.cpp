#include "iostream"
using namespace std;

void merge(int arraySortedInTwoHalves[], int startindex, int length)
{
	int size = (length - startindex) + 1;
	int *b = new int[size]();

	int i = startindex;
	int mid = (startindex + length) / 2;
	int k = 0;
	int j = mid + 1;

	while (k < size)
	{
		if ((i <= mid) && (arraySortedInTwoHalves[i] < arraySortedInTwoHalves[j]))
		{
			b[k++] = arraySortedInTwoHalves[i++];
		}
		else
		{
			b[k++] = arraySortedInTwoHalves[j++];
		}

	}

	for (k = 0; k < size; k++)
	{
		arraySortedInTwoHalves[startindex + k] = b[k];
	}

	delete[]b;
}

void mergeSort(int arrayToSort[], int startindex, int lengthToSort)
{
	int midIndex;

	if (startindex >= lengthToSort)
	{
		return;
	}

	midIndex = (startindex + lengthToSort) / 2;

	mergeSort(arrayToSort, startindex, midIndex);
	mergeSort(arrayToSort, midIndex + 1, lengthToSort);
	merge(arrayToSort, startindex, lengthToSort);
}

int main()
{
	int unsortedArray[10] = { 3,2,1,9 };

	mergeSort(unsortedArray, 0, 3);

	for (int i = 0; i < 4; i++)
	{
		cout << unsortedArray[i] << " ";
	}

	system("pause");
	return 0;
}
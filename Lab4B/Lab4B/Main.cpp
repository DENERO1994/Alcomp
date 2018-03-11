#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryTree *b = new BinaryTree();

	b->add(22);
	b->add(10);
	b->add(25);
	b->add(15);
	b->add(7);

	cout << "Minimum Value: ";
	cout << b->minValue();

	cout << "\n\nMaximum Value: ";
	cout << b->maxValue();

	cout << "\n\nFist BST() function: \n";

	if (b->isBST() == 0)
	{
		cout << "Not Binary Search Tree";
	}
	else
	{
		cout << "Binary Search Tree";
	}

	cout << "\n\nSecond BST2() function: \n";

	if (b->isBST2() == 0)
	{
		cout << "Not Binary Search Tree";
	}
	else
	{
		cout << "Binary Search Tree";
	}

	cout << "\n\n";
	system("pause");
	return 0;
}
#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryTree *b = new BinaryTree();

	cout << "Empty Tree: " << b->height() << "\n\n";			//first output should be -1

	b->add(10);

	cout << "Root element: " << b->height() << "\n\n";			//second output should be 0

	b->add(11);
	b->add(9);

	cout << "Leaf nodes of root: " << b->height() << "\n\n";	//third output should be 1

	b->add(11);

	cout << "Leaf node of leaf: " << b->height() << "\n\n";		//fourth output should be 2....etc.

	if (b->hasPathSum(32) == 1)
	{
		cout << "Path 20 exists";
	}
	else
	{
		cout << "Path 20 doesn't exist";
	}

	cout << "\n\n";

	cout << "Paths:\n";
	b->printPaths();
	
	cout << "\n\n";

	system("pause");
	return 0;
}
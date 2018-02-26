#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryTree *b = new BinaryTree();

	b->add(10);
	b->add(20);
	b->add(30);
	b->add(40);
	b->add(30);
	b->add(40);

	cout << b->height();

	system("pause");
	return 0;
}
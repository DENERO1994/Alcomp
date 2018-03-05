#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryTree *b = new BinaryTree();

	b->add('d');
	b->add('e');
	b->add('n');
	b->add('a');
	b->add('c');
	b->add('r');
	b->add('m');

	if (b->search('z') == true)				//Search for z before inserting z(returns false)
	{
		cout << "z has been found";
	}
	else
	{
		cout << "z hasn't been found";
	}

	b->add('z');							//Insert z
	cout << "\n\n";

	if (b->search('z') == true)				//Search for z after insert(returns true)
	{
		cout << "z has been found";
	}
	else
	{
		cout << "z hasn't been found";
	}

	cout << "\n\nIn order traversal\n";
	b->inorder();

	cout << "\n\nPreorder traversal\n";
	b->preorder();

	cout << "\n\nPostorder traversal\n";
	b->postorder();

	cout << "\n\n";
	system("pause");
	return 0;
}
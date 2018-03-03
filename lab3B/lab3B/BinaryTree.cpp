#include "BinaryTree.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

BinaryTree::BinaryTree() {}

/***************************************************************************************

*    Usage: modified
*    Title: Binary Tree Implementation
*    Author: tobocus
*    Date: 02/03/2018
*    Availability: https://gist.github.com/toboqus/def6a6915e4abd66e922
*
***************************************************************************************/

void BinaryTree::add(int key)
{
	if (root != NULL) {
		add(key, root);
	}
	else {
		root = new TreeNode(key);
		root->left = NULL;
		root->right = NULL;
	}
}

void BinaryTree::add(int key, TreeNode *leaf)
{
	if (key < leaf->data) {
		if (leaf->left != NULL) {
			add(key, leaf->left);
		}
		else {
			leaf->left = new TreeNode(key);
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->data) {
		if (leaf->right != NULL) {
			add(key, leaf->right);
		}
		else {
			leaf->right = new TreeNode(key);
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

/***************************************************************************************

*    Usage: modified
*    Title: Write program to find max depth of a tree
*    Author: GeeksForGeeks
*    Date: 02/03/2018
*    Availability: https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
*
***************************************************************************************/

int BinaryTree::height(TreeNode *root) const
{
	if (root == NULL)
	{
		return -1;
	}
	
	int left = height(root->left);
	int right = height(root->right);

	if (left > right)
	{
		return(left + 1);
	}
	else
		return(right + 1);
}

int BinaryTree::height()
{
	return height(this->root);
}

#include "BinaryTree.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

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

/***************************************************************************************

*    Usage: modified
*    Title: Root to leaf path sum equal to a given number
*    Author: GeeksForGeeks
*    Date: 05/03/2018
*    Availability: https://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/
*
***************************************************************************************/

int BinaryTree::hasPathSum(int sum, TreeNode *node)
{
	if (node == NULL)
	{
		return (sum == 0);
	}

	else
	{
		int ans = 0;

		/* otherwise check both subtrees */
		int subSum = sum - node->data;

		/* If we reach a leaf node and sum becomes 0 then return true*/
		if (subSum == 0 && node->left == NULL && node->right == NULL)
			return 1;

		if (node->left)
			ans = ans || hasPathSum(subSum, node->left);
		if (node->right)
			ans = ans || hasPathSum(subSum, node->right);

		return ans;
	}
}

/***************************************************************************************

*    Usage: modified
*    Title: Given a binary tree, print all root-to-leaf paths
*    Author: GeeksForGeeks
*    Date: 05/03/2018
*    Availability: https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
*
***************************************************************************************/

void BinaryTree::printPaths(TreeNode *node)
{
	int path[1000];
	printPathsRecur(node, path, 0);
}

void BinaryTree::printPathsRecur(TreeNode *node, int path[], int pathLen)
{
	if (node == NULL)
		return;

	/* append this node to the path array */
	path[pathLen] = node->data;
	pathLen++;

	/* it's a leaf, so print the path that led to here  */
	if (node->left == NULL && node->right == NULL)
	{
		printArray(path, pathLen);
	}
	else
	{
		/* otherwise try both subtrees */
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

void BinaryTree::printArray(int ints[], int len)
{
	int i;
	for (i = 0; i<len; i++)
	{
		printf("%d ", ints[i]);
	}
	printf("\n");
}

int BinaryTree::height()
{
	return height(this->root);
}

int BinaryTree::hasPathSum(int sum)
{
	return hasPathSum(sum, root);
}

void BinaryTree::printPaths()
{
	printPaths(root);
}
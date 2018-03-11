#include "BinaryTree.h"
#include <cstdlib>

using namespace std;

BinaryTree::BinaryTree() {}

void BinaryTree::add(int data)
{
	if (root != NULL) {
		add(data, root);
	}
	else {
		root = new TreeNode(data);
		root->left = NULL;
		root->right = NULL;
	}
}

int BinaryTree::minValue()
{
	return minValue(root);
}

int BinaryTree::maxValue()
{
	return maxValue(root);
}

int BinaryTree::isBST()
{
	return isBST(root);
}

int BinaryTree::isBST2()
{
	return isBST2(root);
}

void BinaryTree::add(int data, TreeNode *leaf)
{
	if (data < leaf->data) {
		if (leaf->left != NULL) {
			add(data, leaf->left);
		}
		else {
			leaf->left = new TreeNode(data);
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (data >= leaf->data) {
		if (leaf->right != NULL) {
			add(data, leaf->right);
		}
		else {
			leaf->right = new TreeNode(data);
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

int BinaryTree::minValue(TreeNode *root)
{
	TreeNode* temp = root;
	while (temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp->data;
}

int BinaryTree::maxValue(TreeNode *root)
{
	TreeNode* temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp->data;
}

/***************************************************************************************

*    Usage: modified
*    Title: A program to check if a binary tree is BST or not
*    Author: GeeksForGeeks
*    Date: 11/03/2018
*    Availability: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*
***************************************************************************************/

int BinaryTree::isBST(TreeNode *root)
{
	if (root == NULL)
		return 1;

	if (root->left != NULL && maxValue(root->left) > root->data)
		return 0;

	if (root->right != NULL && minValue(root->right) < root->data)
		return 0;

	if (!isBST(root->left) || !isBST(root->right))
		return 0;

	return 1;
}

int BinaryTree::isBSTRecur(TreeNode *root, int min, int max)
{
	if (root == NULL)
	{
		return 1;
	}

	if (root->data < min || root->data > max)
	{
		return 0;
	}
	
	return
		isBSTRecur(root->left, min, root->data - 1) &&
		isBSTRecur(root->right, root->data + 1, max);
}

int BinaryTree::isBST2(TreeNode *root)
{
	return (isBSTRecur(root, INT_MIN, INT_MAX));
}

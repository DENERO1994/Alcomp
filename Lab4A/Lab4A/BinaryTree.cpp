#include "BinaryTree.h"
#include <cstdlib>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {}

void BinaryTree::add(char data)
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

bool BinaryTree::search(char data)
{
	return search(data, root);
}

void BinaryTree::inorder()
{
	inorder(root);
}

void BinaryTree::preorder()
{
	preorder(root);
}

void BinaryTree::postorder()
{
	postorder(root);
}

/***************************************************************************************

*    Usage: Modified
*    Title: c++ Binary Search Tree
*    Author: dookie
*    Date: 03/03/2018
*    Availability: http://www.cplusplus.com/forum/general/1551/
*
***************************************************************************************/

void BinaryTree::inorder(TreeNode* node)
{
	if (node == NULL)
		return;

	/* first recur on left child */
	inorder(node->left);

	/* then print the data of node */
	cout << node->data;

	/* now recur on right child */
	inorder(node->right);
}

void BinaryTree::preorder(TreeNode *node)
{
	if (node == NULL)
		return;

	/* first print data of node */
	cout << node->data;

	/* then recur on left sutree */
	preorder(node->left);

	/* now recur on right subtree */
	preorder(node->right);
}

void BinaryTree::postorder(TreeNode *node)
{
	if (node == NULL)
		return;

	// first recur on left subtree
	postorder(node->left);

	// then recur on right subtree
	postorder(node->right);

	// now deal with the node
	cout << node->data;
}

void BinaryTree::add(char data, TreeNode *leaf)
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

/***************************************************************************************

*    Usage: modified
*    Title: Binary Trees in c++
*    Author: Alex Allain
*    Date: 03/03/2018
*    Availability: https://www.cprogramming.com/tutorial/lesson18.html
*
***************************************************************************************/

bool BinaryTree::search(char data, TreeNode *leaf)
{
	if (leaf != NULL)
	{
		if (data == leaf->data)
		{
			return true;
		}
		if (data < leaf->data)
		{
			return search(data, leaf->left);
		}
		else
			return search(data, leaf->right);
	}
	else
		return false;
}
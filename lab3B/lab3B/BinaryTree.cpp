#include "BinaryTree.h"
#include <cstdlib>

BinaryTree::BinaryTree(){}

void BinaryTree::add(int data)
{
	if (root != NULL)
	{
		add(data, root);
	}
	else
	{
		root = new TreeNode(data);
		root->left = NULL;
		root->right = NULL;
	}
}

void BinaryTree::add(int data, TreeNode *leaf)
{
	if (data < leaf->data)
	{
		if (leaf->left != NULL)
		{
			add(data, leaf->left);
		}
		else
		{
			leaf->left = new TreeNode(data);
			root->left->left = NULL;
			root->left->right = NULL;
		}
	}
	else if (data >= leaf->data)
	{
		if (leaf->right != NULL)
		{
			add(data, leaf->right);
		}
		else
		{
			leaf->right = new TreeNode(data);
			root->right->left = NULL;
			root->right->right = NULL;
		}
	}
}

int BinaryTree::height()
{
	return 0;
}

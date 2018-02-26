#include "BinaryTree.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

BinaryTree::BinaryTree() {}

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

int BinaryTree::height(TreeNode *root)
{
	if (root == NULL)
	{
		return -1;
	}
	else if (root != NULL && root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	else
	{
		return max(height(root->left), height(root->right)) + 1;
	}
}

int BinaryTree::height()
{
	return height(this->root);
}

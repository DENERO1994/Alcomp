#pragma once

#include <cstdlib>
#include "TreeNode.h"

using namespace std;

template <class T>
class BinaryTree
{
public:
	BinaryTree();
	void add(T);
	bool search(T);
	void inorder();
	int height();
private:
	void add(T, TreeNode<T>*&);
	bool search(T, TreeNode<T>*);
	void inorder(TreeNode<T>*);
	int height(TreeNode<T>*&);
	TreeNode<T>* root;
};

template <class T>
BinaryTree<T>::BinaryTree() {}

template <class T>
void BinaryTree<T>::add(T data)
{
	if (root != NULL) {
		add(data, root);
	}
	else {
		root = new TreeNode<T>(data);
		root->left = NULL;
		root->right = NULL;
	}
}

template <class T>
void BinaryTree<T>::add(T data, TreeNode<T>*& leaf)
{
	if (data < leaf->data) {
		if (leaf->left != NULL) {
			add(data, leaf->left);
		}
		else {
			leaf->left = new TreeNode<T>(data);
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (data >= leaf->data) {
		if (leaf->right != NULL) {
			add(data, leaf->right);
		}
		else {
			leaf->right = new TreeNode<T>(data);
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}
}

template <class T>
void BinaryTree<T>::inorder()
{
	inorder(root);
}

template <class T>
void BinaryTree<T>::inorder(TreeNode<T>* leaf)
{
	if (leaf != NULL)
	{
		inorder(leaf->left);
		cout << leaf->data << "\n";
		inorder(leaf->right);
	}
}

template <class T>
bool BinaryTree<T>::search(T data)
{
	return search(data, root);
}

template <class T>
bool BinaryTree<T>::search(T data, TreeNode<T> *leaf)
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

template <class T>
int BinaryTree<T>::height(TreeNode<T>*& root)
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

template<class T>
int BinaryTree<T>::height()
{
	return height(this->root);
}
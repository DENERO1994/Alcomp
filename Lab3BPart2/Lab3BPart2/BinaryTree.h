#ifndef BinaryTree_h
#define BinaryTree_h

#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree();
	void add(char);
	bool search(char);
	void inorder();
private:
	void add(char, TreeNode*);
	bool search(char, TreeNode*);
	void inorder(TreeNode*);
	TreeNode *root;
};

#endif
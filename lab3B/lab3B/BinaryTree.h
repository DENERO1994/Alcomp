#ifndef BinaryTree_h
#define BinaryTree_h

#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree();
	void add(int);
	int height();
private:
	void add(int, TreeNode*);
	int height(TreeNode*) const;
	TreeNode *root;
};

#endif
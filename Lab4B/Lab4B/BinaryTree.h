#ifndef BinaryTree_h
#define BinaryTree_h

#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree();
	void add(int);
	int minValue();
	int maxValue();
	int isBST();
	int isBST2();
private:
	void add(int, TreeNode*);
	int minValue(TreeNode*);
	int maxValue(TreeNode*);
	int isBST(TreeNode*);
	int isBSTRecur(TreeNode*, int, int);
	int isBST2(TreeNode*);
	TreeNode *root;
};

#endif
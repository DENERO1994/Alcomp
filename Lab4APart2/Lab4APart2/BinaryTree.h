#ifndef BinaryTree_h
#define BinaryTree_h

#include "TreeNode.h"

class BinaryTree
{
public:
	BinaryTree();
	void add(int);
	int height();
	int hasPathSum(int);
	void printPaths();
private:
	void add(int, TreeNode*);
	int height(TreeNode*) const;
	int hasPathSum(int, TreeNode*);
	void printPaths(TreeNode*);
	void printPathsRecur(TreeNode*, int[], int);
	void printArray(int[], int);
	TreeNode *root;
};

#endif
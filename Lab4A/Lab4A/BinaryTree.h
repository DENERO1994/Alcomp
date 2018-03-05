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
	void preorder();
	void postorder();
private:
	void add(char, TreeNode*);
	bool search(char, TreeNode*);
	void inorder(TreeNode*);
	void preorder(TreeNode*);
	void postorder(TreeNode*);
	TreeNode *root;
};

#endif
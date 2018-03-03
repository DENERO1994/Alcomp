#ifndef TreeNode_h
#define TreeNode_h

#include <cstdlib>

using namespace std;

template <class T> class BinaryTree;

template <class T>
class TreeNode
{
public:
	TreeNode(T);
	TreeNode<T> *left;
	TreeNode<T> *right;
	T data;
	friend class BinaryTree<T>;
};

template <class T>
TreeNode<T>::TreeNode(T dataIn) :data(dataIn) {}

#endif
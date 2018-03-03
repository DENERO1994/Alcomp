#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree<int> *integrs = new BinaryTree<int>();			//BinaryTree of ints
BinaryTree<char> *characters = new BinaryTree<char>();		//BinaryTree of chars

//Custom function to print out the result of the search based on whatever type is defined
//uses the is_same function to check the type of the generic type against an integer or a character.

/***************************************************************************************

*    Usage: modified
*    Title: std:is_same
*    Author: cppreference
*    Date: 03/03/2018
*    Availability: http://en.cppreference.com/w/cpp/types/is_same
*
***************************************************************************************/

template <class T>
void search(T data)
{
	if (std::is_same<T, int>::value)						//compare input type with int using is_same function
	{
		if (integrs->search(data) == true)					//Search for integer
		{
			cout << data << " has been found\n";
		}
		else
		{
			cout << data << " hasn't been found\n";
		}
	}
	else
		if (characters->search(data) == true)				//search for character
		{
			cout << data << " has been found\n";
		}
		else
		{
			cout << data << " hasn't been found\n";
		}
}

int main()
{
	integrs->add(22);
	integrs->add(10);
	integrs->add(5);
	integrs->add(11);

	characters->add('h');
	characters->add('b');
	characters->add('e');

	cout << "Integers in Ascending order\n";
	integrs->inorder();						//Print out in ints in ascending order

	cout << "\n\n";

	cout << "Characters in Ascending order\n";
	characters->inorder();					//Print out in chars in ascending order
	
	cout << "\n\n";

	search('z');					//search for z before adding
	characters->add('z');			//add z to charater tree
	search('z');					//search for z after adding

	cout << "\n";
	characters->inorder();
	cout << "\n";

	search(15);						//search for 15 before adding
	integrs->add(15);				//add 15 to integer tree
	search(15);						//search for 15 after adding

	cout << "\n";
	integrs->inorder();

	cout << "\n\nHeight of Integer tree: " << integrs->height();			//print height of integer tree
	cout << "\n\nHeight of Character tree: " << characters->height();		//print height of character tree

	cout << "\n\n";
	system("pause");
	return 0;
}
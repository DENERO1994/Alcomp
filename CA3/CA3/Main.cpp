#include <iostream>
//Map is for storing each character and the frequency of that character
#include <map>
//For reading in a file
#include <fstream>
//For priority queue
#include <queue>
#include<string>
#include <cstdlib>

using namespace std;

//map to store each character and the frequency of that character in the file
map<char, int> characters;
//map to store each character and the huffman value associated with it
map<char, string> codes;

//Struct to store each node of the huffman tree
struct HuffmanNode
{
	//Stores the character and frequency
	char character;
	int frequency;

	//Pointers to the child nodes
	HuffmanNode *left, *right;

	//Constructor to pass in values and set child pointers to null
	HuffmanNode(char character, int frequency)
	{
		left = right = NULL;
		this->character = character;
		this->frequency = frequency;
	}
};

struct compare
{
	bool operator()(HuffmanNode* left, HuffmanNode* right)
	{
		return (left->frequency > right->frequency);
	}
};

void storeCodes(struct HuffmanNode* root, string str)
{
	if (!root)
	{
		return;
	}
		
	if (root->character != '$')
	{
		codes[root->character] = str;
	}
		
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;

void buildHuffmanTree()
{
	HuffmanNode *left, *right, *top;

	for (auto character : characters)
	{
		minHeap.push(new HuffmanNode(character.first, character.second));
	}

	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new HuffmanNode('$', left->frequency + right->frequency);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

//Function to read the encoded file, decode it and write to another file
void writeToDecodedFile(HuffmanNode *root)
{
	ifstream fileIn("encodedFile.txt");
	ofstream fileOut("decodedFile.txt");

	HuffmanNode *current = root;
	char character;

	while ((character = fileIn.get()) != EOF)
	{
		if (character == '0')
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

		if (current->left == NULL && current->right == NULL)
		{
			fileOut << current->character;
			current = root;
		}
	}

	fileIn.close();
	fileOut.close();
}

//Function to write the encoded data to a file
void writeToEncodedFile(string encodedString)
{
	//Declare file to write encoded data to
	ofstream fileOut("encodedFile.txt");

	//Write encoded string into the file
	fileOut << encodedString;

	//Close the file
	fileOut.close();
}

//Function to calculate the frequency of each character in the file and store in a map
void calculateFrequency()
{
	//Read in the text file
	ifstream fileIn("textfile.txt");

	//Char to store each character in the file 
	char character;

	//Loop through each character and add it to the map along with incrementing the frequency
	while ((character = fileIn.get()) != EOF)
	{
		characters[character]++;
	}

	//Close file
	fileIn.close();
}

int main()
{	
	//String to store the encoded huffman values for each character
	string encodedString;

	//Calculate the frequency of each letter, passing the map
	calculateFrequency();

	//Print out each element of the map
	/*for (auto element : characters)
	{
		cout << element.first << " " << element.second << "\n";
	}*/

	//Build the huffman tree passing the character map
	buildHuffmanTree();

	//print out each character of the file with their associated huffman code
	/*for (auto character : codes)
	{
		cout << character.first << " " << character.second << "\n";
	}*/

	for (auto character : characters)
	{
		encodedString += codes[character.first];
	}

	writeToEncodedFile(encodedString);
	writeToDecodedFile(minHeap.top());

	system("pause");
	return 0;
}

//https://stackoverflow.com/questions/5616421/increment-mapstring-int-using-operator
//http://www.dreamincode.net/forums/topic/49604-letter-frequencies-in-a-text-file/
//http://www.cplusplus.com/forum/beginner/66019/
//https://www.geeksforgeeks.org/huffman-decoding/
//https://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding/
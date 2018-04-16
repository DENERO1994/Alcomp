#include <iostream>
//Map is for storing each character and the frequency of that character
#include <map>
//For reading in a file
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	//Read in the text file
	ifstream fileIn("textfile.txt");
	
	//map to store each character and the frequency of that character in the file
	map<char, int> characters;

	//Store each character in the file
	char character = fileIn.get();

	//Loop through each character and add it to the map along with incrementing the frequency
	while (character != EOF)
	{
		characters[character]++;
		character = fileIn.get();
	}

	//Print out each element of the map
	for (auto element : characters)
	{
		cout << element.first << " " << element.second << "\n";
	}

	//Close file
	fileIn.close();

	system("pause");
	return 0;
}

//https://stackoverflow.com/questions/5616421/increment-mapstring-int-using-operator
//http://www.dreamincode.net/forums/topic/49604-letter-frequencies-in-a-text-file/
//http://www.cplusplus.com/forum/beginner/66019/
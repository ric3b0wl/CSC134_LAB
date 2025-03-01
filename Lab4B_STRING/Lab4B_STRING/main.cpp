/////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename:main.cpp
// Date: Oct 25, 2018
// Programmer: Shengkai Xu
//
// Description:
//    A word search program that searches an input data file for a word specified by the user.
// 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Class: main function
//                                                                   
// Description:
//    Main function to call function from source.cpp
// 
/////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "header.h"

int main()
{
	ifstream inFile;
	inFile.open("paragraph.dat");

	if (!inFile.is_open())
	{
		cout << "ERROR, input file could not be opened! \n";
		return 1;
	}

	string word;
	int wordCount = 0, nonVowelCount = 0;

	cout << "Enter a word to find: ";
	cin >> word;

	processFile(inFile, word, wordCount, nonVowelCount);
	displayResult(word, wordCount, nonVowelCount);

	inFile.close();
	
	system("pause");
	return 0;

}

/////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: header.h
// Date: Nov 7, 2018
// Programmer: Shengkai Xu
//
// Description:
//    This program to a program to analyze the 
//    marital status of the combined total of men and women in the US.
// 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Class: main function
//                                                                   
// Description:
//    Function to recall functions and display results.
// 
/////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "header.h"

int main()
{
	string tableHeadings[NUM_HEADINGS];
	string categories[NUM_CATEGORIES];
	
	double catPerc[NUM_CATEGORIES][NUM_PERCENTAGE];
	double combinedPerc[NUM_COMBINED_PERC];
	double highest = 0.0, lowest = 0.0;
	
	char representativeCode[NUM_COMBINED_PERC];

	int high_cnt = 0, norm_cnt = 0, low_cnt = 0;

	ifstream inFile;
	inFile.open("lab5-MaritalStatus2009Survey.txt", ios::in);
	if (!inFile.is_open())
	{
		cout << "Error: Cannot open file...Exiting." << endl;
		system("pause");
		exit(0);
	}

	//Read the input file and populate the arrays.
	read_data(inFile, tableHeadings, categories, catPerc);
	
	//Use the populated category percentage array to derive the combined percentage,
	//count of high, norm and low representation codes.
	analyze_stats(catPerc, combinedPerc, high_cnt, norm_cnt, low_cnt, highest, lowest);

	//assign the representation code to each combined average
	for (int x = 0; x < NUM_COMBINED_PERC; x++)
	{
		if (combinedPerc[x] >= 40.00) representativeCode[x] = 'H';
		else if (combinedPerc[x] >= 25) representativeCode[x] = 'N';
		else representativeCode[x] = 'L';
	}

	/*
	Men Single & Women Single        ==   combinedPerc[0]
	Men Married & Women Married      ==   combinedPerc[1] 
	Men Separated & Women Separated  ==   combinedPerc[2] 
	Men Divorced & Women Divorced    ==   combinedPerc[3] 
	Men Widowed & Women Widowed      ==   combinedPerc[4]
	*/
	cout << "The Representation Code for combined men and women average in each combined category as follow: \n"
		<< "Men Single and Women Single" << "(" << combinedPerc[0] << ") is on code " << representativeCode[0] << endl
		<< "Men Married and Women Married" << "(" << combinedPerc[1] << ") is on code " << representativeCode[1] << endl
		<< "Men Separated and Women Separated" << "(" << combinedPerc[2] << ") is on code " << representativeCode[2] << endl
		<< "Men Divorced and Women Divorced" << "(" << combinedPerc[3] << ") is on code " << representativeCode[3] << endl
		<< "Men Widowed and Women Widowed" << "(" << combinedPerc[4] << ") is on code " << representativeCode[4] << endl << endl;

	//Display the results of each combined marriage catergory
	display_results(categories, combinedPerc, high_cnt, norm_cnt, low_cnt, highest, lowest);


	inFile.close();
	system("pause");
	return 0;
}

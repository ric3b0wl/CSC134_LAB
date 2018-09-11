/////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: main.cpp
// Date: Sep 11, 2018
// Programmer: Shengkai Xu
//
// Description:
//    This program using table data to help calculates the college tuition fee.
// 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Class: main function
//                                                                   
// Description:
//    Function read and check the input of tuition type.
//    Calculate the tuition fee acorrding to the input.
// 
/////////////////////////////////////////////////////////////////////////////////////

//#include "stdafx.h"
#include "pch.h"
#include "header.h"

int main()
{
	int tuition_type = 0;
	
	cout << "(1) In State Tuition \n"
		 << "(2) Out State Tuition \n"
		 << "Please enter tuition type by using (1/2) \n";

	while (true) //giving options for tuition type
	{
		cin >> tuition_type; //read input

		if (tuition_type == 1 || tuition_type == 2)// checking input
		{
			break;
		}

		else
		{
			cout << "ERROR, Please type either 1 or 2 for selection! \n";
			cin.clear();
			cin.ignore(1, '/n');
			continue;
		}
	}

	switch (tuition_type)
	{
		case 1: cout << "You choosed In State " << endl;
		{
			break;
		}
	
		case 2: cout << "You choosed Out State " << endl;
		{
			break;
		}
	}

	system("pause");

	return 0;

}


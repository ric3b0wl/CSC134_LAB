/////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: header.h
// Date: Oct 1, 2018
// Programmer: Shengkai Xu
// 
// Description:
//    This program using three different functions to calculate the employee gross pay.
// 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Class: main function
//                                                                   
// Description:
//    Function to calculate child tax credit.
// 
/////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "header.h"

int main()
{
	double weekly_grosspay = 0.00; //using "double" to avoid funture data type issues
	calcPay(weekly_grosspay); //void funstions

	cout << "This weekly gross pay for this employee is: $" << weekly_grosspay << endl;
	// display the final result

	system("pause");
	return 0;
}

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

	tuition_fx();

	/*
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
	*/

	int crdt_hrs = 0;
	float total_fee = 0;

	switch (tuition_type)
	{
		case 1: cout << "You choosed In State Tuition \n"
					 << "Please type in number of credit hours: " << endl;
			
			while (true)
			{
				cin >> crdt_hrs;
				cout << "\n";

				if (crdt_hrs > 0)
				{
					cout << "+ $76 per credit \n"
						<< "+ Computer/Tech fee: $3 per credit \n"
						<< "+ Student activity fee: $35 \n"
						<< "+ Computer access fee: $85 \n" << endl;
					
					total_fee = crdt_hrs * 76;
					total_fee += (3 * crdt_hrs);
					total_fee += (35 + 85);

					cout << "Your fee total is: $" << total_fee << "\n" << endl;
					break;
				}

				else
				{
					cout << "ERROR, Please type in vaild credit hours! \n";
					cin.clear();
					cin.ignore(1, '/n');
					continue;
				}
			}
			break;

		case 2: cout << "You choosed Out State Tuition \n"
					 << "Please type in number of credit hours: " << endl;

			while (true)
			{
				cin >> crdt_hrs;
				cout << "\n";

				if (crdt_hrs > 0)
				{
					cout << "+ $268 per credit \n"
						<< "+ Computer/Tech fee: $3 per credit \n"
						<< "+ Student activity fee: $35 \n"
						<< "+ Computer access fee: $85 \n" << endl;

					total_fee = crdt_hrs * 268;
					total_fee += (3 * crdt_hrs);
					total_fee += (35 + 85);

					cout << "Your fee total is: $" << total_fee << "\n" << endl;
					break;
				}

				else
				{
					cout << "ERROR, Please type in vaild credit hours! \n";
					cin.clear();
					cin.ignore(1, '/n');
					continue;
				}
			}
			break;
	}




	system ("pause");

	return 0;

}


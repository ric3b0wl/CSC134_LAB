/////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: main.cpp
// Date: Nov 23, 2018
// Programmer: Shengkai Xu
//
// Description:
//    This program that creates an array of 10 Account objects.
//		User can use array of 10 object to browsing the account information.
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
#include "Account.h"

int main()
{
	Account account[10];

	float LO = 1.5;
	float HI = 2.0;

	/*
	num = rand() % (how many numbers included in range) + (lowest number in the range)

	This will generate a number from some arbitrary LO to some arbitrary HI:
	float r3 = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
	*/

	for (int x = 0; x < 8; x++)
	{
		account[x] = Account(x, rand() % 100 + 100, LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (HI - LO))));	
		
	}
	
	while (true)
	{
		cout << "Please choose 0 to 9 for account number, or -1 to exit. \n";

		int accountNumber = -1;
		cin >> accountNumber;

		if (accountNumber == -1) break; //input check
		else if (accountNumber > 9 || accountNumber < 0) continue;

		while (true)
		{
			cout << "\nEnter 1 to make a deposit\n"
				<< "Enter 2 to make a withdraw\n"
				<< "Enter 3 to check balance\n"
				<< "Enter 4 to check interest rate\n"
				<< "Enter 5 to display account summary\n"
				<< "Enter 99 to exit to the main menu to select another account number.\n";

			int menuNum = 99;
			double depositNum = 0.00;
			double withdrawNum = 0.00;

			cout << "\nYour menu selection: ";
			cin >> menuNum;
			
			switch (menuNum)
			{
			case 1: //deposit option menu
				cout << "Enter the amount you wish to deposit:";
				cin >> depositNum;
				account[accountNumber].deposit(depositNum); //use dot(.) access the public methods and member from class
				break;

			case 2: //withdraw option menu
				cout << "Enter the amount you wish to withdraw:";
				cin >> withdrawNum;
				account[accountNumber].withdraw(withdrawNum);
				break;

			case 3: //checking balance
				cout << "\nChecking balance...... \n\n";
				cout << "Your balance is:" << account[accountNumber].getBalance() << endl;
				break;

			case 4: //checking interest rate, giving monthly and annually
				cout << "\nGetting your interest rate...... \n\n";
				cout << "Your monthly interest rate is:" << account[accountNumber].getMonthlyInterestRate()
				<< "\n Your annually interest rate is:" << account[accountNumber].getInterest();
				break;

			case 5: //checking account summary
				cout << "\nGetting your account summary...... \n\n"
					<< "Account ID: " << account[accountNumber].getAccountId() << endl
					<< "Balance: " << account[accountNumber].getBalance() << endl
					<< "Monthly Interest Rate: " << account[accountNumber].getMonthlyInterestRate() << endl
					<< "Monthly Interest Amount: " << account[accountNumber].getMonthlyInterest() << endl;
				break;

			case 99: //first loop break, return to account menu
				break;

			default: 
				cout << "Error, Please choose 0 to 9 for account number, or -1 to exit.";
				break;
			}
			if (menuNum == 99) break; //second loop break, return to account menu
		}
	}
}



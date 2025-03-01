/////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: main.cpp
// Date: August 25, 2018
// Programmer: Shengkai Xu
//
// Description:
//    This program using gaven Marginal Tax Rate and Effective Tax Rate,
//    It calculates the an total income taxes and income after taxes accodring
//    to the annual salary input.
//
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Class: main function
//                                                                   
// Description:
//    Function read and check the input of tax rate type.
//    It giving order to run other function codes according to the input value.
// 
/////////////////////////////////////////////////////////////////////////////////////

#include "pch.h"
#include "header.h"


int main()
{
	int tax_type = 0;
	cout << "Welcome to 2017 Taxes Calculator! \n";

	cout << "(1) Marginal Tax Rate \n"
	 	 << "(2) Effective Tax Rate \n"
	 	 << "Please choose the type of tax rate:" << endl;

	bool op = true;

	while (op) //giving options for tax type
	{
		cin >> tax_type; //read input

		if (tax_type == 1 || tax_type == 2)// checking input
		{
			op = false;
		}
		
		else
		{
			cout << "ERROR, Please type either 1 or 2 for selection! \n";
			cin.clear();
			cin.ignore(10000, '/n');
			op = true;
		}
	}

	//all detail datas
	float m_ferdaltax = 0.25;
	float e_ferdaltax = 0.1172;
	float ficatax = 0.0765;
	float m_statetax = 0.0550;
	float e_statetax = 0.0462;
	float localtax = 0;

	double annual_salary;
	double total_income_taxes;
	double income_after_taxes;

	switch (tax_type)
	{
		case 1: cout << "You choosed Marginal Tax Rate \n" //marginal tax case
					 << "enter the annual salary:" << endl;
			
			while (true) 
			{
				cin >> annual_salary; //read input

				if (annual_salary > 0) //calculation
				{
					total_income_taxes = annual_salary * (m_ferdaltax + ficatax + m_statetax + localtax);
					cout << "Total income taxes:" << total_income_taxes << endl;

					income_after_taxes = annual_salary - total_income_taxes;
					cout << "Income after taxes:" << income_after_taxes << endl;

					break;
				}

				else //output error
				{
					cout << "ERROR, try again! \n";
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
			}
			break;

		case 2: cout << "You choosed Effective Tax Rate \n" //effective tax case
					 << "enter the annual salary:" << endl;
			
			while (true) 
			{
				cin >> annual_salary; //readinput

				if (annual_salary > 0) //calculation
				{
					total_income_taxes = annual_salary * (e_ferdaltax + ficatax + e_statetax + localtax);
					cout << "Total income taxes:" << total_income_taxes << endl;

					income_after_taxes = annual_salary - total_income_taxes;
					cout << "Income after taxes:" << income_after_taxes << endl;
				}

				else //output error
				{
					cout << "ERROR, try again! \n";
					cin.clear();
					cin.ignore(10000, '/n');
					continue;
				}
			}
			break;
	}
	return 0;

}
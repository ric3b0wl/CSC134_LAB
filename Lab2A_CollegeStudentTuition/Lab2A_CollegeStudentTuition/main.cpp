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

#include <stdio.h>
#include "pch.h"
#include "header.h"

int main()
{
	string student_name;
	
	cout << "Your name is: ";
	getline(cin, student_name);

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
			cout << "ERROR, Please type either 1 or 2 for selection! \n"; //error option
			cin.clear();
			cin.ignore(1, '/n');
			continue;
		}
	}
	
	double crdt_hrs = 0;
	double total_fee = 0;

	switch (tuition_type)
	{
		case 1: 
			total_fee = instate_cal();
			break;
			
		case 2: 
			total_fee = outstate_cal();
			break;
	}

	//choosing health plane
	cout << "(N) I dont want a health plan for now \n"
		<< "(E) Plan E: $40 \n"
		<< "(S) Plan S: $160 \n"
		<< "(C) Plan C: $120 \n" 
		<< "(F) Plane F: $200 \n"
		<< "Please choose optional health plan as above: " << endl;
	
	char health_plan;

	while (true) //input health plane option
	{		
		cin >> health_plan; //read input
		health_plan = toupper(health_plan);

		if (health_plan == 'N' || health_plan == 'E' || health_plan ==  'S' || health_plan ==  'C' || health_plan == 'F')// checking input
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
	
	double updated_fee = 0.0;
	if (health_plan == 'E')
	{
		updated_fee = total_fee + 40;
	}
	else if (health_plan == 'S')
	{
		updated_fee = total_fee + 160;
	}
	else if (health_plan == 'C')
	{
		updated_fee = total_fee + 120;
	}
	else if (health_plan == 'F')
	{
		updated_fee = total_fee + 200;
	}
	else
	{
		updated_fee = total_fee + 0;
	}


	cout << "Your updated total tuition fee with health plan is: $" << updated_fee << endl;
	
	cout << "Exporting the data to \"tuition_report.txt\""; //wait
	for (int i = 0; i < 10; i++) //for loop dots loading :P
	{
		Sleep(500);
		cout << ".";
	}

// output data to .txt

	ofstream outData("employee_summary.txt");

	if (!outData.is_open())
	{
		cout << "ERROR, output file could not be opened! \n";
		return 1;
	}

	string tuition_status = (tuition_type == 1) ? "In State Tuition" : "Out State Tuition";

	outData
		<< "Name: " << student_name << "\n"
		<< "Tuition Status: " << tuition_status << "\n"
		<< "Health Plan Type: " << health_plan << "\n"
		<< "Total Tuition Fee: $" << updated_fee << endl;

	outData.close();

	cout << "Done" << endl;

	system ("pause");

	return 0;
}


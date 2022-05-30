/*
Coursework

Author         - Daniils Grammatikopulo 
student code   - st79101
Date           - 30.05.2022

Main goal of this coursework is to provide Database where you can
store information about patient, information about their problems
and reviews. And mostly it is done for doctors to check
information, sort/filter/rtemove it or just outputting data.

*/

/********************************************************
   Begin of file "main.cpp"
 ********************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <regex>
#include <algorithm>
#include "fort.hpp"
#include "PatientInfo.h"
#include "PatientProblem.h"
#include "TreatmentProcess.h"
#include "DoctorMenu.h"

// Macros to clear buffer, it's done for inputs
#define BUFFERCLEAR	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

using namespace std;

void Project()
{
	
	system("chcp 65001");						   // for library libfort
	system("cls");								   // clear console 
	vector<PatientInfo> patients_info; 			   //-|
	vector<PatientProblem> patients_problem;	   // |-> vectors for database       
	vector<TreatmentProcess> patients_review;	   //-|

	ReadInfo(patients_info);					   //-|
	ReadProblem(patients_problem);				   // |-> To get info from database
	ReadReview(patients_review);				   //-|
	char option = '0';
	while (option != 'q')
	{
		cout << "+---+----------------------------------+\n"
			<< "| 1 | Fill your info                   |\n"
			<< "+---+----------------------------------+\n"
			<< "| 2 | Get your info                    |\n"
			<< "+---+----------------------------------+\n"
			<< "| 3 | Get info of all                  |\n"
			<< "+---+----------------------------------+\n"
			<< "| 4 | Fill patient problem             |\n"
			<< "+---+----------------------------------+\n"
			<< "| 5 | Find problem(s) by personal code |\n"
			<< "+---+----------------------------------+\n"
			<< "| 6 | Evaluate our company             |\n"
			<< "+---+----------------------------------+\n"
			<< "| 7 | Read all reviews                 |\n"
			<< "+---+----------------------------------+\n"
			<< "| 8 | Doctor menu                      |\n"
			<< "+---+----------------------------------+\n"
			<< "| q | Quit                             |\n"
			<< "+---+----------------------------------+\n\n";
		cout << "Input: ";
		cin >> option;
		BUFFERCLEAR
			switch (option)
			{
			case '1':
				system("CLS");											  //
				cout << "Fill your info\n";								  // First option for patient
				try														  // it will ask user for info
				{														  // more detailed in files 
					patients_info.push_back(GetInfo(patients_info)); 	  // "PatientInfo.cpp"
				}														  //
				catch (const exception& e)								  //
				{														  //
					cerr << e.what();									  //
				}														  //
				system("cls");											  //
				break;													  //
																		 
			case '2':
				system("cls");
				FindPatient(patients_info);
				cout << "\n\nAny input:";
				cin.ignore();
				BUFFERCLEAR
					system("cls");
				break;

			case '3':
				system("cls");
				cout << patients_info;
				cout << "\n\nAny input:";
				cin.ignore();
				BUFFERCLEAR
					system("cls");
				break;

			case '4':
				system("CLS");
				cout << "Fill patient problem \n";
				try
				{
					patients_problem.push_back(GetProblem(patients_info));
				}
				catch (const exception& e)
				{
					cerr << e.what();
				}
				break;

			case '5':
				system("cls");
				cout << "Find problem(s) by personal code\n";
				FindProblem(patients_problem);
				cout << "\n\nAny input:";
				cin.ignore();
				BUFFERCLEAR
					system("cls");
				break;

			case '6':
				system("CLS");
				cout << "Evaluate our company\n";
				try
				{
					patients_review.push_back(GetReview(patients_problem));
				}
				catch (const exception& e)
				{
					cerr << e.what();
				}
				system("cls");
				break;

			case '7':
				system("CLS");
				PrintReviews(patients_info, patients_problem, patients_review);
				cout << "\n\nAny input:";
				cin.ignore();
				BUFFERCLEAR
					system("cls");
				break;
			case '8':
				system("CLS");
				Doctormenu(patients_info, patients_problem, patients_review);
				break;
			case 'q':
				system("CLS");
				cout << "You have quitted from the program!\n";
				WriteProblem(patients_problem);
				WriteInfo(patients_info);
				WriteReview(patients_review);
				return;
			default:
				system("CLS");
				cout << "ERROR" << endl;
				if (option == '0')
				{
					cout << "Something goes wrong!" << endl;
				}
				break;
			}

	}
	WriteProblem(patients_problem);
	WriteInfo(patients_info);
	WriteReview(patients_review);
}

int main()
{
	Project();
}
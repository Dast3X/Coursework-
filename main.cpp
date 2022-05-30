/*
Coursework

Author         - Daniils Grammatikopulo 
student code   - st79101
Date           - 30.05.2022

Main goal of this coursework is to provide Database where you can
store information about patient, information about their problems
and reviews. And mostly it is done for doctors to check
information, sort or filter or remove it or just outputting data.

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

///Brief desc.
///Macros to clear buffer, it's done for inputs
#define BUFFERCLEAR	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

using namespace std;

///Brief desc. It is the function of whole project, basically it just outputs menu\n
///Detailed desc.\n
/// 1) It creates three vectors patients_info, patients_problem, patients_review to store infromation 
/// while program is working\n
/// 2) It Reads data in from a binary files\n
/// 3) It outputs menu\n
/// 4) Options of menu:
///   -  Fill your info
///   -  Get your info 
///   -  Get info of all (it's done to make easier checking info)
///   -  Fill patient problem
///   -  Find problem(s) by personal code
///   -  Evaluate our company
///   -  Read all reviews
///   -  Doctor menu 
///   -  Quit  


void Menu()
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
				cout << "Fill your info\n";								  // 1st option for patient
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
				system("cls");					// 2nd option for patient
				FindPatient(patients_info);		// it will find patient by personal code									
				cout << "\n\nAny input:";		// by personal code more detailed in files 
				cin.ignore();					// "PatientInfo.cpp"
				BUFFERCLEAR						//
					system("cls");				//
				break;							//
			case '3':
				system("cls");				   //
				cout << patients_info;		   // 3nd option for patient
				cout << "\n\nAny input:";	   // it will print out all patient	
				cin.ignore();				   // by personal code more detailed in files
				BUFFERCLEAR					   // "PatientInfo.cpp"
					system("cls");			   //
				break;						   //
			case '4':															  
				system("CLS");													  //
				cout << "Fill patient problem \n";								  //  4th option for patient
				try																  //  it will ask to fill problem	
				{																  //  by personal code more detailed in files
					patients_problem.push_back(GetProblem(patients_info));		  //  "PatientProblem.cpp"
				}																  //
				catch (const exception& e)										  //
				{																  //
					cerr << e.what();											  //
				}																  //
				break;                                                            //
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
	Menu();
}
/*
Coursework: Medical records

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

///\brief
///Macros to clear buffer, it's done for inputs
#define BUFFERCLEAR	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

using namespace std;

///\brief It is the function of whole project, basically it just outputs menu\n\n
/// <b>Detailed desc.</b>
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
	
	system("chcp 65001");						   
	system("cls");	
	// temporary storage for information
	vector<PatientInfo> patients_info; 			   
	vector<PatientProblem> patients_problem;	         
	vector<TreatmentProcess> patients_review;	   

	ReadInfo(patients_info);					   
	ReadProblem(patients_problem);				   
	ReadReview(patients_review);				   
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
			// Enter detailed info on the patient
			case '1':                                                     
				system("CLS");											  
				cout << "Fill your info\n";								  
				try														  
				{														  
					patients_info.push_back(GetInfo(patients_info)); 	  
				}														  
				catch (const exception& e)								  
				{														  
					cerr << e.what();									  
				}														  
				system("cls");											  
				break;		
			// Find patient by personal code
			case '2':							 
				system("cls");					
				FindPatient(patients_info);										
				cout << "\n\nAny input:";							
				system("cls");				
				break;	
			// Get info of all patients
			case '3':
				system("cls");				   
				cout << patients_info;		   
				cout << "\n\nAny input:";	   
				cin.ignore();				   
				BUFFERCLEAR					   
					system("cls");			   
				break;	
		    // Fill patient(s) problem
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
				system("CLS");
				break; 
			// Find problem(s) by personal code
			case '5':
				system("cls");									  
				cout << "Find problem(s) by personal code\n";	  
				FindProblem(patients_problem);					  									  
				system("cls");								  
				break;
			// Get review from patient
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
			// Print all reviews
			case '7':
				system("CLS");													 
				PrintReviews(patients_info, patients_problem, patients_review);	 	
				cout << "\n\nAny input:";										 
				cin.ignore();													 
				BUFFERCLEAR
					system("cls");
				break;
			// Go to Doctor Menu
			case '8':
				system("CLS");													
				Doctormenu(patients_info, patients_problem, patients_review);	
				break;															
			// Quit the program																	
			case 'q':
				system("CLS");												    
				cout << "You have quitted from the program!\n";				   
				WriteProblem(patients_problem);								   
				WriteInfo(patients_info);									    
				WriteReview(patients_review);								   
				return;
			// ERROR
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
	// Save info in binary files
	WriteProblem(patients_problem);		 
	WriteInfo(patients_info);			 
	WriteReview(patients_review);		 
}

 
/// \brief 
/// Calls function Menu() 
int main()
{
	// to call function Menu()
	Menu();  
}
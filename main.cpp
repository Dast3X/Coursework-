#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "fort.hpp"
#include "PatientInfo.h"
#include "PatientProblem.h"
#include "TreatmentProcess.h"
#include <regex>
#include <algorithm>
#include "DoctorMenu.h"

#define BUFFERCLEAR	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;

int main()
{
	system("chcp 65001");
	system("cls");
	vector<PatientInfo> patients_info;
	vector<PatientProblem> patients_problem;
	vector<TreatmentProcess> patients_review;
	ReadInfo(patients_info);
	ReadProblem(patients_problem);
	ReadReview(patients_review);
	char option = '0';
	while (option != '9')
	{
		option = '0';
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
		cin >> option;
		BUFFERCLEAR
		switch (option)
		{
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
			break;

		case '2':
			system("cls");
			FindPatient(patients_info);
			break;

		case '3':
			system("cls");
			cout << patients_info;
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
			break;

		case '6':
			system("CLS");
			cout << "Evaluate our company\n";
			try
			{
				patients_review.push_back(GetReview(patients_info, patients_problem));
			}
			catch (const exception& e)
			{
				cerr << e.what();
			}
			break;

		case '7':
			system("CLS");
			PrintReviews(patients_info, patients_problem, patients_review);
			break;
		case '8':
			system("CLS");
			Doctormenu(patients_info, patients_problem, patients_review);
			break;
		case 'q':
			system("CLS");
			cout << "You have quitted from the program!\n";
			break;
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
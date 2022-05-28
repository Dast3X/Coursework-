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
#define BUFFERCLEAR	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');


using namespace std;

void PatientData(const vector<PatientInfo>& patients_info, const vector<PatientProblem>& patients_problem)
{

	fort::utf8_table table;
	table.set_border_style(FT_NICE_STYLE);
	table.column(0).set_cell_text_align(fort::text_align::center);
	table.column(1).set_cell_text_align(fort::text_align::center);
	table.column(2).set_cell_text_align(fort::text_align::center);
	table.column(3).set_cell_text_align(fort::text_align::center);
	table.column(4).set_cell_text_align(fort::text_align::center);
	table.column(5).set_cell_text_align(fort::text_align::center);


	table << fort::header
		<< "Name" << "Surname" << "Personal code" << "Date" << "Problem" << fort::endr;
	string temp;
	for (const auto& i : patients_info)
	{
		for (const auto& j : patients_problem)
		{
			if (string(i.personal_code) == string(j.personal_code) && j.sick == true)
			{
				temp = string(j.problem, 11);
				table << i.name << i.surname << i.personal_code;
				table << j.starting_date << temp << fort::endr;

			}
		}

	}
	cout << table.to_string() << endl;
}
void Doctormenu(const vector<PatientInfo>& patients_info, vector<PatientProblem>& patients_problem)
{
	string password;
	char option = '0';
	cout << "password: ";
	cin >> password;
	system("cls");
	if (password == "12345") {
		while (option != '7')
		{
			string code;
			option = 'q';
			cout << "+---+----------------------------------+\n"
				<< "| 1 | Get info of patients             |\n"
				<< "+---+----------------------------------+\n"
				<< "| 2 | Find problem(s) by personal code |\n"
				<< "+---+----------------------------------+\n"
				<< "| s | Sorting                          |\n"
				<< "+---+----------------------------------+\n"
				<< "| q | Quit                             |\n"
				<< "+---+----------------------------------+\n\n";
			cin >> option;
			switch (option)
			{
			case '1':
				system("cls");
				PatientData(patients_info, patients_problem);
				break;
			case '2':
				system("cls");
				FindProblem(patients_problem);
				break;
			case 's':
				sort(patients_info.begin(), patients_info.end());
				for (int i = 0; i < patients_info.size(); i++)
				cout << patients_info[i].name << ", ";

				cout << endl;
				break;
			case 'q':
				system("cls");
				cout << "\nYou have quitted menu!\n";
				return;
			default:
				cout << "\nERROR" << endl;
				if (option == '0')
				{
					cout << "Something goes wrong!" << endl;
					return;
				}
				break;
			}
		}
	}
	if (password == "back")
	{
		system("CLS");
		return;
	}
	else
	{
		system("cls");
		cout << "Incorrect password\n";
		return;
	}
}

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
			Doctormenu(patients_info, patients_problem);
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
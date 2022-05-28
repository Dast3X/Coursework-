#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "fort.hpp"
#include "PatientInfo.h"
#include "PatientProblem.h"
#include "TreatmentProcess.h"
#include <regex>



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


	for (const auto& i : patients_info)
	{
		for (const auto& j : patients_problem)
		{
			if (string(i.personal_code) == string(j.personal_code) && j.sick == true)
			{
				table << i.name << i.surname << i.personal_code;
				table << j.starting_date << j.problem << fort::endr;

			}
		}

	}
	cout << table.to_string() << endl;
}
void Doctormenu(const vector<PatientInfo>& patients_info, vector<PatientProblem>& patients_problem)
{

	system("CLS");
	char option = '0';
	while (option != '7')
	{
		string code;
		option = '0';
		cout << "+---+----------------------------------+\n"
			<< "| 1 | Get info of patients             |\n"
			<< "+---+----------------------------------+\n"
			<< "| 2 | Find problem(s) by personal code |\n"
			<< "+---+----------------------------------+\n"
			<< "| 3 | Quit                             |\n"
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
			cout << "Please Enter personal code: ";
			while (true)
			{
				cin >> code;
				if (code == "back") { break; }
				if (isvalid_data(code, R"re(\d{6}-\d{5})re"))
				{
					break;
				}
				else
				{
					system("cls");
					cout << "Incorrect input(s). Try again!\n";
					cout << "Enter your personal code: ";
				}
			}
			if (code != "back") {
				system("cls");
				FindProblem(patients_problem, code);
			}
			break;
		case '3':
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

int main()
{
	system("chcp 65001");
	system("cls");
	string password;
	vector<PatientInfo> patients_info;
	vector<PatientProblem> patients_problem;
	vector<TreatmentProcess> patients_review;
	string code;
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
			<< "| 9 | Quit                             |\n"
			<< "+---+----------------------------------+\n\n";
		cin >> option;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (option)
		{

		case '1':
			system("CLS");
			cout << "Fill your info\n";
			patients_info.push_back(GetInfo(patients_info));
			break;

		case '2':
			system("cls");
			cout << "Get your info\n";
			cout << "Please Enter personal code: ";
			while (true)
			{
				cin >> code;
				if (code == "back") { break; }
				if (isvalid_data(code, R"re(\d{6}-\d{5})re"))
				{
					break;
				}
				else
				{
					system("cls");
					cout << "Incorrect input(s). Try again!\n";
					cout << "Enter your personal code: ";
				}
			}
			system("cls");
			if (code != "back")
				FindPatient(patients_info, code);
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
			cout << "Please Enter personal code: ";
			while (true)
			{
				cin >> code;
				if (code == "back") { break; }
				if (isvalid_data(code, R"re(\d{6}-\d{5})re"))
				{
					break;
				}
				else
				{
					system("cls");
					cout << "Incorrect input(s). Try again!\n";
					cout << "Enter your personal code: ";
				}
			}
			if (code != "back") 
			{
				system("cls");
				FindProblem(patients_problem, code);
			}	
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
			cout << "password: ";
			cin >> password;
			if (password == "12345")
				Doctormenu(patients_info, patients_problem);
			else
				cout << "Incorrect password\n";
			break;
		case '9':
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
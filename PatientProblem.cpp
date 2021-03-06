#include "PatientProblem.h"

#define BUFFERCLEAR cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std; 

void WriteProblem(vector<PatientProblem>& patients_problem)
{
	string file{ "patients_problems.dat" };
	ofstream fs;
	fs.open(file, ofstream::out | ofstream::binary);
	for (auto& i : patients_problem)
		fs.write(reinterpret_cast<char*>(&i), sizeof(PatientProblem));
	fs.close();
}

void ReadProblem(vector<PatientProblem>& patients_problem)
{
	string file{ "patients_problems.dat" };
	ifstream fs;
	fs.open(file, ifstream::in | ifstream::binary);
	if (!fs.is_open())
		cout << "patients_problems.dat - empty file" << endl;
	else
	{
		cout << "Reading data in from a binary file!" << endl;
		PatientProblem tempproblem;
		while (fs.read(reinterpret_cast<char*>(&tempproblem), sizeof(PatientProblem)))
			patients_problem.push_back(tempproblem);
		fs.close();
		return;
	}
	fs.close();
}

PatientProblem GetProblem(const vector<PatientInfo>& patients_info)
{
	PatientProblem problem;
	string tpersonal_code, tdate;
	bool temp{ false };
	cout << "Enter your personal code: ";
	while (true)
	{
		cin >> tpersonal_code;
		BUFFERCLEAR
		if (isvalid_data(tpersonal_code, R"re(\d{6}-\d{5})re"))
		{
			break;
		}
		else if (tpersonal_code == "back")
		{
			system("cls");
			throw runtime_error("");
		}
		else
		{
			system("cls");
			cout << "Incorrect input(s). Try again!\n";
			cout << "Enter your personal code: ";
		}
	}

	for (const auto& i : patients_info)
	{
		if (tpersonal_code == i.personal_code)
		{
			temp = true;
			break;
		}
	}
	if (temp == false)
	{
		throw runtime_error("You should register yourself as patient before filling the problem!\n");
	}
	else
	{
		problem.sick = true;
		strcpy_s(problem.personal_code, tpersonal_code.c_str());
		cout << "\nLet us begin!\n";
		cout << "What is your problem?: ";
		cin.getline(problem.problem, 24);
		cout << "Please describe your problem: ";
		cin.getline(problem.description, 1024);
		cout << "Enter a starting date (dd.mm.yyyy): ";

		while (true)
		{
			cin >> tdate;
			BUFFERCLEAR
			if (isvalid_data(tdate, R"re(^([0-2][0-9]|(3)[0-1])(\.)(((0)[0-9])|((1)[0-2]))(\.)(((202)[0-2])|((2)(0)[0-1][0-9]))$)re")) {

				strcpy_s(problem.starting_date, tdate.c_str());
				break;
			}
			else
			{

				cout << "\nIncorrect input(s). Try again!\n";
				cout << "Enter a starting date (dd.mm.yyyy): ";
			}
		}
		return problem;
	}

}

void FindProblem(vector<PatientProblem>& patients_problem)
{
	string tpersonal_code;
	cout << "Please Enter personal code: ";
	while (true)
	{
		cin >> tpersonal_code;
		BUFFERCLEAR
		if (tpersonal_code == "back") { system("cls");  return; }
		if (isvalid_data(tpersonal_code, R"re(\d{6}-\d{5})re"))
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
	bool temp{ false };
	for (const auto& i : patients_problem)
	{
		if (tpersonal_code == i.personal_code)
		{
			cout << "Personal_code: " << i.personal_code
				<< "\nStarting date: " << i.starting_date
				<< "\nProblem: " << i.problem
				<< "\nDescription: " << i.description
				<< "\n\n";
			temp = true;
			continue;
		}
	}

	if (temp == false)
	{
		cout << "Personal code was not found or patient didn't fill problem!";
		cout << "\n\nAny input:";
		cin.ignore();
		BUFFERCLEAR
		return;
	}
	cout << "\n\nAny input:";
	cin.ignore();
	BUFFERCLEAR
}
#include "PatientProblem.h"

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
		cout << "error" << endl;
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
	string tpersonal_code;
	bool temp{ false };
	cout << "Enter your personal code: ";
	cin >> tpersonal_code;
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
		cin.ignore();
		cin.getline(problem.problem, 256);
		cout << "Please describe your problem: ";
		cin.getline(problem.description, 2048);
		cout << "Enter a starting date (dd/mm/yyyy): ";
		cin >> problem.starting_date;
		return problem;
	}

}

void FindProblem(vector<PatientProblem>& patients_problem, string& code)
{
	bool temp{ false };
	for (const auto& i : patients_problem)
	{
		if (code == i.personal_code)
		{
			cout << "\nPersonal_code: " << i.personal_code
				<< "\nStarting date: " << i.starting_date
				<< "\nProblem: " << i.problem
				<< "\nDescription: " << i.description
				<< "\n\n";
			temp = true;
			continue;
		}
	}
	if (false)
	{
		cout << "Personal code was not found!";
		return;
	}
}
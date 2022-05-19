#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>


using namespace std;

struct TreatmentProcess
{
	char discharge_date[32]{};
	char treatment[2048]{};
	char comment[2048]{};
};


struct PatientInfo
{
	char name[64]{};
	char surname[64]{};
	unsigned short age{};
	char personal_code[64]{};
	char phone_number[64]{};
};

struct PatientProblem
{
	char personal_code[64]{};
	char starting_date[32]{};
	char problem[256]{};
	char description[2048]{};
};
void WriteProblem(vector<PatientProblem>& patients_problem)
{
	string file{ "patients_problems.dat" };
	ofstream fs;
	fs.open(file, ofstream::out | ofstream::binary);
	for (unsigned int i = 0; i < patients_problem.size(); i++)
		fs.write(reinterpret_cast<char*>(&patients_problem[i]), sizeof(PatientProblem));
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
		while (fs.read(reinterpret_cast<char*>(&tempproblem), sizeof(PatientInfo)))
			patients_problem.push_back(tempproblem);
		fs.close();
	}

}
PatientProblem GetProblem(const vector<PatientInfo>& patients_info)
{
	PatientProblem problem;
	string tpersonal_code;
	bool temp{ false };
	cout << "Enter your personal code: ";
	cin >> tpersonal_code;
	for (auto& i : patients_info)
	{
		if (tpersonal_code == i.personal_code)
		{
			temp = true;
			break;
		}
	}
	if (temp == false)
	{
		cout << "You should register yourself as patient before filling the problem!\n";
		return problem;
	}
	else
	{
		strcpy_s(problem.personal_code, tpersonal_code.c_str());
		cout << "\nLet us start!\n";
		cout << "Enter a starting date: ";
		cin >> problem.starting_date;
		cout << "What is your problem?: ";
		cin.getline(problem.problem, 256);
		cout << "Please describe your problem: ";
		cin.getline(problem.description, 2048);
		return problem;
	}

}
void FindProblem(vector<PatientProblem>& patients_problem, string& code)
{
	for (auto& i : patients_problem)
	{
		if (code == i.personal_code)
		{
			cout << "\nPersonal_code: " << i.personal_code
				<< "\nStarting date: " << i.starting_date
				<< "\nProblem: " << i.problem
				<< "\nDescription: " << i.description
				<< "\n\n";
			return;
		}
	}
	cout << "Personal code was not found!";
}






ostream& operator<<(ostream& os, const vector<PatientInfo>& patients_info)
{
	for (auto& i : patients_info)
	{
		os << "\nName: \t" << i.name
			<< "\nSurname: \t" << i.surname
			<< "\nAge: \t" << i.age
			<< "\nPersonal code: \t" << i.personal_code
			<< "\nPhone number: \t" << i.phone_number
			<< "\n\n";
	}
	return os;
}
PatientInfo GetInfo()
{
	PatientInfo patient;
	cout << "Enter your name: ";
	cin >> patient.name;
	cout << "Enter your surname: ";
	cin >> patient.surname;
	cout << "Enter your age: ";
	cin >> patient.age;
	cout << "Enter your personal code (e.g 12345-54321): ";
	cin >> patient.personal_code;
	cout << "Enter your phone number (e.g +3712345678): ";
	cin >> patient.phone_number;
	return patient;
}
void WriteInfo(vector<PatientInfo>& patients_info)
{
	string file{ "patients.dat" };
	ofstream fs;
	fs.open(file, ofstream::out | ofstream::binary);
	for (unsigned int i = 0; i < patients_info.size(); i++)
		fs.write(reinterpret_cast<char*>(&patients_info[i]), sizeof(PatientInfo));
	fs.close();
}
void ReadInfo(vector<PatientInfo>& patients_info)
{
	string file{ "patients.dat" };
	ifstream fs;
	fs.open(file, ifstream::in | ifstream::binary);
	if (!fs.is_open())
		cout << "error" << endl;
	else
	{
		cout << "Reading data in from a binary file!" << endl;
		PatientInfo temppatient;
		while (fs.read(reinterpret_cast<char*>(&temppatient), sizeof(PatientInfo)))
			patients_info.push_back(temppatient);
		fs.close();
	}

}
void FindPatient(vector<PatientInfo>& patients_info, string& code)
{
	for (auto& i : patients_info)
	{
		if (code == i.personal_code)
		{
			cout << "\nName: " << i.name
				<< "\nSurname: " << i.surname
				<< "\nAge: " << i.age
				<< "\nPersonal code: " << i.personal_code
				<< "\nPhone number: " << i.phone_number
				<< "\n\n";
			return;
		}
	}
	cout << "Personal code was not found!";
}


int main()
{
	vector<PatientInfo> patients_info;
	vector<PatientProblem> patients_problem;
	string code;
	ReadInfo(patients_info);
	ReadProblem(patients_problem);
	char option = '0';
	while (option != '7')
	{
		option = '0';
		cout << endl
			<< "+---+----------------------------------+\n"
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
			<< "| 6 | Read all reviews                 |\n"
			<< "+---+----------------------------------+\n"
			<< "| 7 | Quit                             |\n"
			<< "+---+----------------------------------+\n\n";
		cin >> option;
		switch (option)
		{
			
		case '1':
			patients_info.push_back(GetInfo());
			break;

		case '2':
			cout << "\nPlease Enter personal code: ";
			cin >> code;
			FindPatient(patients_info, code);
			break;

		case '3':
			cout << patients_info;
			break;

		case '4':
			patients_problem.push_back(GetProblem(patients_info));
			break;

		case '5':
			cout << "\nPlease Enter personal code: ";
			cin >> code;
			FindProblem(patients_problem, code);
			break;
		case '7':
			cout << "\nYou have quitted from the program!\n";
			break;

		default:
			cout << "\nERROR" << endl;
			if (option == '0')
			{
				cout << "Something goes wrong!" << endl;
				WriteProblem(patients_problem);
				WriteInfo(patients_info);
				return 0;
			}
			break;
		}
	}
	WriteProblem(patients_problem);
	WriteInfo(patients_info);
}
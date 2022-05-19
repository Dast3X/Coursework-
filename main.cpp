#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <exception>
#include <chrono>

using namespace std;

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
	char problem[256];
	char description[2048]{};
};

struct TreatmentProcess
{
	char personal_code[64]{};
	char discharge_date[32]{};
	char treatment[2048]{};
	char comment[2048]{};
};

void WriteReview(vector<TreatmentProcess>& patients_review)
{
	string file{ "patients_treatment_review.dat" };
	ofstream fs;
	fs.open(file, ofstream::out | ofstream::binary);
	for (unsigned int i = 0; i < patients_review.size(); i++)
		fs.write(reinterpret_cast<char*>(&patients_review[i]), sizeof(TreatmentProcess));
	fs.close();
}
void ReadReview(vector<TreatmentProcess>& patients_review)
{
	string file{ "patients_treatment_review.dat" };
	ifstream fs;
	fs.open(file, ifstream::in | ifstream::binary);
	if (!fs.is_open())
		cout << "error" << endl;
	else
	{
		cout << "Reading data in from a binary file!" << endl;
		TreatmentProcess temptreatment;
		while (fs.read(reinterpret_cast<char*>(&temptreatment), sizeof(TreatmentProcess)))
			patients_review.push_back(temptreatment);
		fs.close();
	}

}
TreatmentProcess GetReview(const vector<PatientInfo>& patients_info, const vector<PatientProblem>& patients_problem)
{
	TreatmentProcess review;
	string tpersonal_code, tproblem;
	bool temp{ false };
	cout << "Enter your personal code: ";
	cin >> tpersonal_code;
	cout << "Choose your problem \n";
	for (const auto& k : patients_problem)
	{
		if (k.personal_code == tpersonal_code)
			cout << '\t' << k.problem << '\n';
		else
		{
			cout << "You can't choose because you have not filled problem\n";
		}
	}

	cin >> tproblem;

	for (const auto& i : patients_problem)
	{
		if (tpersonal_code == string(i.personal_code) && tproblem == string(i.problem))
		{
			temp = true;
			break;
		}
	}
	if (temp == false)
	{
		throw runtime_error("You should fill your problem before filling review!\n");
	}
	else
	{
		strcpy_s(review.personal_code, tpersonal_code.c_str());
		cout << "\nLet us begin!\n";
		cout << "Enter a discharge date (dd/mm/yyyy): ";
		cin >> review.discharge_date;
		cout << "Describe the treatment process: ";
		cin.ignore();
		cin.getline(review.treatment, 2048);
		cout << "What'd you recommend?: ";
		cin.getline(review.comment, 2048);
		return review;
	}
}
void PrintReviews(const vector<PatientInfo>& p_info, const vector<PatientProblem>& p_problem, const vector<TreatmentProcess>& p_review)
{
	cout << "Reviews:\n\n";
	for (const auto& i : p_review)
	{
		for (const auto& j : p_info)
		{
			if (string(i.personal_code) == string(j.personal_code))
			{
				cout << "\nPatient: " << j.name << " (" << j.age << ") " << j.surname << '\n';
				break;
			}
		}
		for (const auto& j : p_problem)
		{
			if (string(i.personal_code) == string(j.personal_code))
			{
				cout << "Problem: " << j.problem << '\n'
					 << "Date: " << j.starting_date << " - " << i.discharge_date << '\n';
				break;
			}
		}
		cout << "Treatment: " << i.treatment << '\n'
			<< "Recommendation: " << i.comment <<'\n';
		return;
	}
	cout << "We don't have reviews yet :( why it is so?";
}

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
		strcpy_s(problem.personal_code, tpersonal_code.c_str());
		cout << "\nLet us begin!\n";
		cout << "Enter a starting date (dd/mm/yyyy): ";
		cin >> problem.starting_date;
		cout << "What is your problem?: ";
		cin.ignore();
		cin.getline(problem.problem, 256);
		cout << "Please describe your problem: ";
		cin.getline(problem.description, 2048);
		return problem;
	}

}
void FindProblem(vector<PatientProblem>& patients_problem, string& code)
{
	bool temp{false};
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


ostream& operator<<(ostream& os, const vector<PatientInfo>& patients_info)
{
	for (const auto& i : patients_info)
	{
		os << "\nName: " << i.name
			<< "\nSurname: " << i.surname
			<< "\nAge: " << i.age
			<< "\nPersonal code: " << i.personal_code
			<< "\nPhone number: " << i.phone_number
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
	for (const auto& i : patients_info)
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

void Doctormenu(const vector<PatientInfo>& patients_info, const vector<PatientProblem>& patients_problem)
{
	char option = '0';
	while (option != '7')
	{
		option = '0';
		cout << endl
			<< "+---+----------------------------------+\n"
			<< "| 1 | Get info of patients             |\n"
			<< "+---+----------------------------------+\n"
			<< "| 2 | Quit                             |\n"
			<< "+---+----------------------------------+\n\n";
		cin >> option;
		switch (option)
		{
		case '1':

			break;
		case '2':
			cout << "\nYou have quitted menu!\n";
			break;
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
			<< "| 6 | Evaluate our company             |\n"
			<< "+---+----------------------------------+\n"
			<< "| 7 | Read all reviews                 |\n"
			<< "+---+----------------------------------+\n"
			<< "| 8 | Doctor menu                      |\n"
			<< "+---+----------------------------------+\n"
			<< "| 9 | Quit                             |\n"
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
			try
			{
				patients_problem.push_back(GetProblem(patients_info));
			}
			catch (const std::exception& e)
			{
				cerr << e.what();
			}
			break;

		case '5':
			cout << "\nPlease Enter personal code: ";
			cin >> code;
			FindProblem(patients_problem, code);
			break;

		case '6':
			try
			{
				patients_review.push_back(GetReview(patients_info, patients_problem));
			}
			catch (const std::exception& e)
			{
				cerr << e.what();
			}
			break;

		case '7':
			PrintReviews(patients_info, patients_problem, patients_review);
			break;
		case '8':
			//doctormenu();
			break;
		case '9':
			cout << "\nYou have quitted from the program!\n";
			break;
		default:
			cout << "\nERROR" << endl;
			if (option == '0')
			{
				cout << "Something goes wrong!" << endl;
				WriteProblem(patients_problem);
				WriteInfo(patients_info);
				WriteReview(patients_review);
				return 0;
			}
			break;
		}
	}
	WriteProblem(patients_problem);
	WriteInfo(patients_info);
	WriteReview(patients_review);
}
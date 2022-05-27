#include "functions.h"
#include "data_struct.h"

void WriteReview(vector<TreatmentProcess>& patients_review)
{
	string file{ "patients_treatment_review.dat" };
	ofstream fs;
	fs.open(file, ofstream::out | ofstream::binary);
	for (auto& i : patients_review)
		fs.write(reinterpret_cast<char*>(&i), sizeof(TreatmentProcess));
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
		return;
	}
	fs.close();
}
TreatmentProcess GetReview(const vector<PatientInfo>& patients_info, vector<PatientProblem>& patients_problem)
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
	}
	cout << "Problem: ";
	cin.ignore();
	getline(cin, tproblem);

	for (auto& i : patients_problem)
	{
		if (tpersonal_code == string(i.personal_code) && tproblem == string(i.problem))
		{
			temp = true;
			i.sick = false;
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
			<< "Recommendation: " << i.comment << '\n';
		return;
	}
	cout << "We don't have reviews yet :( why it is so?";
}


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


void WriteInfo(vector<PatientInfo>& patients_info)
{
	string file{ "patients.dat" };
	ofstream fs;
	fs.open(file, ofstream::out | ofstream::binary);
	for (auto& i : patients_info)
		fs.write(reinterpret_cast<char*>(&i), sizeof(PatientInfo));
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
		return;
	}
	fs.close();
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
void Doctormenu(const vector<PatientInfo>& patients_info, const vector<PatientProblem>& patients_problem)
{

	system("CLS");
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
			PatientData(patients_info, patients_problem);
			break;
		case '2':
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

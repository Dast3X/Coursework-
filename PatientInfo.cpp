#include "PatientInfo.h"

using namespace std;



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
	string tpc, tnum, tage, lv{"+371"};
	PatientInfo patient;
	cout << "Enter your name: ";
	cin >> patient.name;
	cout << "Enter your surname: ";
	cin >> patient.surname;
	cout << "Enter your age: ";

	while (true)
	{
		cin >> tage;
		if (isvalid_data(tage, R"re(\d{2})re") || isvalid_data(tage, R"re(\d{1})re"))
		{
			patient.age = stoi(tage);
			break;
		}
		else
		{
			cout << "\nIncorrect input(s). Try again!\n";
			cout << "Enter your age: ";
		}
	}
	cout << "Enter your personal code (e.g 123456-54321): ";
		
	while (true)
	{
		cin >> tpc;
		if (isvalid_data(tpc, R"re(\d{6}-\d{5})re"))
		{
			strcpy_s(patient.personal_code, tpc.c_str());
			break;
		}
		else
		{
			cout << "\nIncorrect input(s). Try again!\n";
			cout << "Enter your personal code (e.g 123456-54321): ";
		}
	}

	cout << "Enter your phone number (e.g 22345678): ";

	while (true)
	{
		cin >> tnum;
		if (isvalid_data(tnum, R"re(\d{8})re"))
		{ 
			lv += tnum;
			strcpy_s(patient.phone_number, lv.c_str());
			break;
		}
		else
		{

			cout << "\nIncorrect input(s). Try again!\n";
			cout << "Enter your LV phone number (e.g 22345678): ";
		}
	}
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
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
	string tage, tpc, tphn;
	PatientInfo patient;
	cout << "Enter your name: ";
	cin >> patient.name;
	cout << "Enter your surname: ";
	cin >> patient.surname;
	cout << "Enter your age: ";
	cin >> patient.age;
	cout << "Enter your personal code (e.g 12345-54321): ";
	cin >> tage;
	 
	patient.personal_code;
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
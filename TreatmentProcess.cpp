#include "TreatmentProcess.h"

using namespace std;

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
		if (k.personal_code == tpersonal_code && k.sick == true)
			cout << '\t' << k.problem << '\n';
	}
	cout << "Problem: ";
	cin.ignore();
	getline(cin, tproblem);
	for (auto& i : patients_problem)
	{
		if (tpersonal_code == string(i.personal_code) && tproblem == string(i.problem) && i.sick == true)
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
					<< "Date: " << j.starting_date << " - " << i.discharge_date << '\n' << '\n';
			}
		}
		cout << "Treatment: " << i.treatment << '\n'
			<< "Recommendation: " << i.comment << '\n';
		return;
	}
	cout << "We don't have reviews yet :( why it is so?";
}
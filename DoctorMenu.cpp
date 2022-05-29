#include "DoctorMenu.h"
#define BUFFERCLEAR cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;
void RemovePatient(vector<PatientInfo>& p_info, vector<PatientProblem>& p_problem, vector<TreatmentProcess>& p_review)
{
	string tpersonal_code;
	unsigned int pos;
	cout << "Choose patient you want to remove from DB\n";
	for (unsigned short i = 0; i < p_info.size(); i++)
	{
		cout << i << ". " << p_info.at(i).personal_code << '\n';
	}
	cout << "\nInput: ";
	cin >> pos;
	BUFFERCLEAR
		if (pos > p_info.size() || pos < 0)
		{
			return;
		}
	tpersonal_code = string(p_info.at(pos).personal_code);
	p_info.erase(p_info.begin() + pos);
	for (unsigned int i = 0; i < p_problem.size(); i++)
	{
		if (tpersonal_code == p_problem.at(i).personal_code)
		{
			p_problem.erase(p_problem.begin() + i);
			i = 0;
		}
	}
	for (unsigned int i = 0; i < p_review.size(); i++)
	{
		if (tpersonal_code == p_review.at(i).personal_code)
		{
			p_review.erase(p_review.begin() + i);
			i = 0;
		}
	}
	cout << "\nPatient - " << tpersonal_code << " has been removed\n";
}
void Sorting(vector<PatientInfo>& p_info)
{
	string opt;
	system("cls");
	while (true)
	{
		cout << "1 - sort by age\n2 - sort by name\nback - return\n\nInput:";
		cin >> opt;
		cout << '\n';
		BUFFERCLEAR
			if (opt == "back")
			{
				return;
			}
		if (opt == "1")
		{
			system("cls");
			cout << "SORTING BY AGE\n\nbefore: \n";
			for (const auto& i : p_info)
				cout << "(" << i.name << " " << i.surname << " " << i.age << ")\n";
			cout << '\n';
			sort(p_info.begin(), p_info.end(),
				[](auto& p1, auto& p2) {
					return p1.age > p2.age;
				});
			cout << "\nafter: \n";
			for (const auto& i : p_info)
				cout << "(" << i.name << " " << i.surname << " " << i.age << ")\n";
			cout << '\n';
		}
		else if (opt == "2")
		{
			system("cls");
			cout << "SORTING BY NAME\n\nbefore: \n";

			for (const auto& i : p_info)
				cout << "(" << i.name << " " << i.surname << " " << i.age << ")\n";
			cout << '\n';
			sort(p_info.begin(), p_info.end(), [](auto& name1, auto& name2) {
				return strcmp(name1.name, name2.name) < 0;
				});
			cout << "after: \n";
			for (const auto& i : p_info)
				cout << "(" << i.name << " " << i.surname << " " << i.age << ")\n";
			cout << '\n';
		}
		else
		{
			continue;
		}
	}

}
void Quantity(const vector<PatientInfo>& p_info, const vector<PatientProblem>& p_problem, const vector<TreatmentProcess>& p_review)
{

	cout << "Amount of patients: " << p_info.size();
	cout << "\nAmount of problems: " << p_problem.size();
	cout << "\nAmount of reviews: " << p_review.size() << '\n';
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
	string temp;
	for (const auto& i : patients_info)
	{
		for (const auto& j : patients_problem)
		{
			if (string(i.personal_code) == string(j.personal_code) && j.sick == true)
			{
				temp = string(j.problem, 10);
				table << i.name << i.surname << i.personal_code;
				table << j.starting_date << temp << fort::endr;

			}
		}

	}
	cout << table.to_string() << endl;
}
void Doctormenu(vector<PatientInfo>& p_info, vector<PatientProblem>& p_problem, vector<TreatmentProcess>& p_review)
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
				<< "| 3 | Quantity                         |\n"
				<< "+---+----------------------------------+\n"
				<< "| s | Sorting                          |\n"
				<< "+---+----------------------------------+\n"
				<< "| r | Remove patient                   |\n"
				<< "+---+----------------------------------+\n"
				<< "| q | Quit                             |\n"
				<< "+---+----------------------------------+\n\n";
			cin >> option;
			switch (option)
			{
			case '1':
				system("cls");
				PatientData(p_info, p_problem);
				break;
			case '2':
				system("cls");
				FindProblem(p_problem);
				break;
				for (const auto& i : p_info)
					cout << i.name << " " << i.name << " " << i.name << '\n';
			case '3':
				system("cls");
				Quantity(p_info, p_problem, p_review);
				break;
			case 's':
				Sorting(p_info);
				break;
			case 'r':
				system("cls");
				RemovePatient(p_info, p_problem, p_review);
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
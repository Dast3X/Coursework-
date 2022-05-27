#pragma once
#include <vector>
#include <regex>
#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <cstring>
#include "PatientInfo.h"
#include "Validation.h"

struct PatientProblem
{
	char personal_code[64]{};
	char starting_date[32]{};
	char problem[256]{};
	char description[2048]{};
	bool sick{ false };
};

void WriteProblem(std::vector<PatientProblem>& patients_problem);

void ReadProblem(std::vector<PatientProblem>& patients_problem);

PatientProblem GetProblem(const std::vector<PatientInfo>& patients_info);

void FindProblem(std::vector<PatientProblem>& patients_problem, std::string& code);
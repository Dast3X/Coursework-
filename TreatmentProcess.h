#pragma once
#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <exception>
#include "fort.hpp"
#include "PatientProblem.h"
#include "PatientInfo.h"
#include "TreatmentProcess.h"
#include "Validation.h"

struct TreatmentProcess
{
	char personal_code[16]{};
	char discharge_date[16]{};
	char treatment[256]{};
	char comment[1024]{};
	char problem[24]{};
};




void WriteReview(std::vector<TreatmentProcess>& patients_review);

void ReadReview(std::vector<TreatmentProcess>& patients_review);

TreatmentProcess GetReview(const std::vector<PatientInfo>& patients_info, std::vector<PatientProblem>& patients_problem);

void PrintReviews(const std::vector<PatientInfo>& p_info, const std::vector<PatientProblem>& p_problem, const std::vector<TreatmentProcess>& p_review);
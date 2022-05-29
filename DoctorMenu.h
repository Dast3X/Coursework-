#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "fort.hpp"
#include "PatientInfo.h"
#include "PatientProblem.h"
#include "TreatmentProcess.h"
#include <algorithm>


void Filtering(const std::vector<PatientInfo>& p_info, const std::vector<PatientProblem>& p_problems);
void RemovePatient(std::vector<PatientInfo>& p_info, std::vector<PatientProblem>& p_problem, std::vector<TreatmentProcess>& p_review);
void Sorting(std::vector<PatientInfo>& p_info);
void Quantity(const std::vector<PatientInfo>& p_info, const std::vector<PatientProblem>& p_problem, const std::vector<TreatmentProcess>& p_review);
void PatientData(const std::vector<PatientInfo>& patients_info, const std::vector<PatientProblem>& patients_problem);
void Doctormenu(std::vector<PatientInfo>& p_info, std::vector<PatientProblem>& p_problem, std::vector<TreatmentProcess>& p_review);
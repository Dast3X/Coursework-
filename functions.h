#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <exception>
#include <chrono>
#include "fort.hpp"
#include "data_struct.h"

void WriteReview(vector<TreatmentProcess>& patients_review);
void ReadReview(vector<TreatmentProcess>& patients_review);
TreatmentProcess GetReview(const vector<PatientInfo>& patients_info, vector<PatientProblem>& patients_problem);
void PrintReviews(const vector<PatientInfo>& p_info, const vector<PatientProblem>& p_problem, const vector<TreatmentProcess>& p_review);


void WriteProblem(vector<PatientProblem>& patients_problem);
void ReadProblem(vector<PatientProblem>& patients_problem);
PatientProblem GetProblem(const vector<PatientInfo>& patients_info);
void FindProblem(vector<PatientProblem>& patients_problem, string& code);

void WriteInfo(vector<PatientInfo>& patients_info);
void ReadInfo(vector<PatientInfo>& patients_info);
ostream& operator<<(ostream& os, const vector<PatientInfo>& patients_info);
PatientInfo GetInfo();
void FindPatient(vector<PatientInfo>& patients_info, string& code);


void PatientData(const vector<PatientInfo>& patients_info, const vector<PatientProblem>& patients_problem);
void Doctormenu(const vector<PatientInfo>& patients_info, const vector<PatientProblem>& patients_problem);



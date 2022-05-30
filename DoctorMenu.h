#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "fort.hpp"
#include "PatientInfo.h"
#include "PatientProblem.h"
#include "TreatmentProcess.h"
#include <algorithm>

/// <summary>
/// Function for filtering information by age(patients), by letter(problems), by year(patients).
/// </summary>
/// <param name="p_info">is vector of PatientInfo structure which temporary store info about patients info</param>
/// <param name="p_problem">is vector of PatientProblem structure which temporary store info about problems</param>
void Filtering(const std::vector<PatientInfo>& p_info, const std::vector<PatientProblem>& p_problems);

/// <summary>
/// Function for removing all information about patient.
/// </summary>
/// <param name="p_info">is vector of PatientInfo structure which temporary store info about patients info</param>
/// <param name="p_problem">is vector of PatientProblem structure which temporary store info about problems</param>
/// <param name="p_review">is vector of TreatmentProcess structure which temporary store info about reviews</param>
void RemovePatient(std::vector<PatientInfo>& p_info, std::vector<PatientProblem>& p_problem, std::vector<TreatmentProcess>& p_review);

/// <summary>
/// Function for sorting patients by age, by name.
/// </summary>
/// <param name="p_info">is vector of PatientInfo structure which temporary store info about patients info</param>
void Sorting(std::vector<PatientInfo>& p_info);

/// <summary>
/// Function to output amount of patients, problems, reviews.
/// </summary>
/// <param name="p_info">is vector of PatientInfo structure which temporary store info about patients info</param>
/// <param name="p_problem">is vector of PatientProblem structure which temporary store info about problems</param>
/// <param name="p_review">is vector of TreatmentProcess structure which temporary store info about reviews</param>
void Quantity(const std::vector<PatientInfo>& p_info, const std::vector<PatientProblem>& p_problem, const std::vector<TreatmentProcess>& p_review);

/// <summary>
/// Function to output patient and patient's problem(s) in ascii table.
/// </summary>
/// <param name="patients_info">is vector of PatientInfo structure which temporary store info about patients info</param>
/// <param name="patients_problem">is vector of PatientProblem structure which temporary store info about problems</param>
void PatientData(const std::vector<PatientInfo>& patients_info, const std::vector<PatientProblem>& patients_problem);

///\brief It is the function of doctor menu\n\n
/// <b>Detailed desc.</b>
/// 1) p_info p_problem p_review are passed in Doctormenu()\n
/// 2) It outputs menu\n
/// 3) Options of menu:
///   -  Get info of patients 
///   -  Find problem(s) by personal code
///   -  Quantity
///   -  Sorting
///   -  Filtering
///   -  Remove patient
///   -  Quit  
/// <param name="p_info">is vector of PatientInfo structure which temporary store info about patients info</param>
/// <param name="p_problem">is vector of PatientProblem structure which temporary store info about problems</param>
/// <param name="p_review">is vector of TreatmentProcess structure which temporary store info about reviews</param>
void Doctormenu(std::vector<PatientInfo>& p_info, std::vector<PatientProblem>& p_problem, std::vector<TreatmentProcess>& p_review);
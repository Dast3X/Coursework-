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
	/// personal code -- char array with the size 16 
	char personal_code[16]{};
	/// discharge date -- char array with the size 16 
	char discharge_date[16]{};
	/// treatment -- char array with the size 256. Description about treatment process
	char treatment[256]{};
	/// comment -- char array with the size 1024. Comments about treatment
	char comment[1024]{};
	/// problem -- char array with the size 24
	char problem[24]{};
};



/// <summary>
/// This function is for writing patient's problems out into a binary file
/// </summary>
/// <param name="patients_review">is vector of TreatmentProcess structure which temporary store info about reviews</param>
void WriteReview(std::vector<TreatmentProcess>& patients_review);

/// <summary>
/// This function is for reading data in from a binary file
/// </summary>
/// <param name="patients_review">is vector of TreatmentProcess structure which temporary store info about reviews</param>
void ReadReview(std::vector<TreatmentProcess>& patients_review);

/// <summary>
/// This function asks patient to input personal code and choose the problem. And if it is in the DB
/// patient will be allowed to fill review. You can write 'back' to return
/// </summary>
/// <param name="patients_problem">is vector of PatientProblem structure which temporary store info about problems</param>
/// <returns>TreatmentProcess</returns>
TreatmentProcess GetReview(std::vector<PatientProblem>& patients_problem);

/// <summary>
/// Function for printing out all reviews
/// </summary>
/// <param name="p_info">is vector of PatientInfo structure which temporary store info about patients info</param>
/// <param name="p_problem">is vector of PatientProblem structure which temporary store info about problems</param>
/// <param name="p_review">is vector of TreatmentProcess structure which temporary store info about reviews</param>
void PrintReviews(const std::vector<PatientInfo>& p_info, const std::vector<PatientProblem>& p_problem, const std::vector<TreatmentProcess>& p_review);
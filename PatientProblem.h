#pragma once
#include <vector>
#include <regex>
#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <cstring>
#include <limits>
#include "PatientInfo.h"
#include "Validation.h"


/// <summary>
/// \brief
/// It's a structure which stores info about 
/// - personal code
/// - starting date 
/// - problem
/// - description
/// - sick
/// </summary>
struct PatientProblem
{
	/// personal code -- char array with the size 16 
	char personal_code[16]{};
	/// starting date -- char array with the size 16 
	char starting_date[16]{};
	/// problem -- char array with the size 24 
	char problem[24]{};
	/// description -- char array with the size 1024 to describe the problem in details 
	char description[1024]{};
	/// sick -- bool for checking whether patient is sick
	bool sick{ false };
};

/// <summary>
/// This function is for writing patient's problems out into a binary file
/// </summary>
/// <param name="patients_problem">is vector of PatientProblem structure which temporary store info about problems</param>
void WriteProblem(std::vector<PatientProblem>& patients_problem);

/// <summary>
/// This function is for reading data in from a binary file
/// </summary>
/// <param name="patients_problem">is vector of PatientProblem structure which temporary store info about problems</param>
void ReadProblem(std::vector<PatientProblem>& patients_problem);

/// <summary>
/// This function asks patient to input personal code. And if it is in the patients_info
/// patient will be allowed to fill problem. You can write 'back' to return
/// </summary>
/// <param name="patients_info">is vector of PatientInfo structure which temporary store info about patients</param>
/// <returns>PatientProblem</returns>
PatientProblem GetProblem(const std::vector<PatientInfo>& patients_info);

/// <summary>
/// Function for finding patient's problem(s) by personal code. You can write 'back' to return
/// </summary>
/// <param name="patients_problem">is vector of PatientProblem structure which temporary store info about problems</param>
void FindProblem(std::vector<PatientProblem>& patients_problem);
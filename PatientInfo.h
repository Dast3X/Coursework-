#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "Validation.h"
#include <limits>
/// <summary>
///\brief 
/// It's a structure which stores info about 
/// - name
/// - surname 
/// - age 
/// - personal code 
/// - phone number
/// </summary>
struct PatientInfo
{
	
	/// name -- char array with the size 16 
	char name[16]{};
	/// surname -- char array with the size 16 
	char surname[16]{};
	/// age -- unsigned short
	unsigned short age{};
	/// personal code -- char array with the size 16 
	char personal_code[16]{};
	/// phone number -- char array with the size 16 
	char phone_number[16]{};
};

/// <summary>
/// This function is for writing patients info out into a binary file
/// </summary>
/// <param name="patients_info">is vector of PatientInfo structure which temporary store info about patients</param>
void WriteInfo(std::vector<PatientInfo>& patients_info);

/// <summary>
/// This function is for reading data in from a binary file
/// </summary>
/// <param name="patients_info">is vector of PatientInfo structure which temporary store info about patients</param>
void ReadInfo(std::vector<PatientInfo>& patients_info);

/// <summary>
///	Functions which overloads << operator to output UDT(PatientInfo)	
/// </summary>
/// <param name="os"> ostream for overloading operator <<</param>
/// <param name="patients_info">is vector of PatientInfo structure which temporary store info about patients</param>
/// <returns>os for std::cout </returns>
std::ostream& operator<<(std::ostream& os, const std::vector<PatientInfo>& patients_info);

/// <summary>
/// Function for filling info about patient. At the beginning when it asks for personal code you can write 'back' to return to menu.
/// </summary>
/// <param name="patient_info">is vector of PatientInfo structure which temporary store info about patients</param>
/// <returns>PatientInfo</returns>
/// 
PatientInfo GetInfo(const std::vector<PatientInfo>& patient_info);

/// <summary>
/// Function for finding patient info by personal code. You can write 'back' to return
/// </summary>
/// <param name="patient_info">is vector of PatientInfo structure which temporary store info about patients</param>
void FindPatient(std::vector<PatientInfo>& patients_info);
#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "Validation.h"
/// <summary>
/// <b>Brief desc.</b> 
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
/// <param name="patients_info"> is vector of Patient Info structure which temporary store info about patients</param>
void WriteInfo(std::vector<PatientInfo>& patients_info);

void ReadInfo(std::vector<PatientInfo>& patients_info);

std::ostream& operator<<(std::ostream& os, const std::vector<PatientInfo>& patients_info);

PatientInfo GetInfo(const std::vector<PatientInfo>& patient_info);

void FindPatient(std::vector<PatientInfo>& patients_info);
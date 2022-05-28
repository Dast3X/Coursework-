#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "Validation.h"

struct PatientInfo
{
	char name[16]{};
	char surname[16]{};
	unsigned short age{};
	char personal_code[16]{};
	char phone_number[16]{};
};

void WriteInfo(std::vector<PatientInfo>& patients_info);

void ReadInfo(std::vector<PatientInfo>& patients_info);

std::ostream& operator<<(std::ostream& os, const std::vector<PatientInfo>& patients_info);

PatientInfo GetInfo(const std::vector<PatientInfo>& patient_info);

void FindPatient(std::vector<PatientInfo>& patients_info, std::string& code);
#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "Validation.h"

struct PatientInfo
{
	char name[64]{};
	char surname[64]{};
	unsigned short age{};
	char personal_code[64]{};
	char phone_number[64]{};

};

void WriteInfo(std::vector<PatientInfo>& patients_info);

void ReadInfo(std::vector<PatientInfo>& patients_info);

std::ostream& operator<<(std::ostream& os, const std::vector<PatientInfo>& patients_info);

PatientInfo GetInfo();

void FindPatient(std::vector<PatientInfo>& patients_info, std::string& code);
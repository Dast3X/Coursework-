#pragma once

struct PatientProblem
{
	char personal_code[64]{};
	char starting_date[32]{};
	char problem[256]{};
	char description[2048]{};
	bool sick{ false };
};

struct PatientInfo
{
	char name[64]{};
	char surname[64]{};
	unsigned short age{};
	char personal_code[64]{};
	char phone_number[64]{};

};

struct TreatmentProcess
{
	char personal_code[64]{};
	char discharge_date[32]{};
	char treatment[2048]{};
	char comment[2048]{};
};

#include "Validation.h"

using namespace std;

bool isvalid_data(const string& data, const string& str_re)
{
	regex re{ str_re };
	return regex_match(data, re);
}
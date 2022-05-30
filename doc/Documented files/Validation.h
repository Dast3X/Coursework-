#pragma once
#include <regex>
#include <string>
/// <summary>
/// Validation for user's inputs
/// </summary>
/// <param name="data">User's input</param>
/// <param name="str_re"> Regex expression</param>
/// <returns>bool {true|false}</returns>
bool isvalid_data(const std::string& data, const std::string& str_re);



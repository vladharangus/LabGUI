#pragma once
#include <string>
#include <exception>
#include "ValidatorException.h"
#include <vector>
#include "Statue.h"
class Validator
{
public:
	Validator();
	static void validate_arguments(const std::string& wordname, const std::string& material, const int& age, const std::string& corporealForm);
	static void validate_statue(Statue statue, std::vector<Statue> list_of_statues);
	~Validator();
};


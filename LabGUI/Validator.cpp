#include "pch.h"
#include "Validator.h"
#include <iostream>


Validator::Validator()
{
}

void Validator::validate_arguments(const std::string & wordname, const std::string & material, const int & age, const std::string & corporealForm)
{
	if (wordname == "")
		throw ValidatorException("Wrong wordaname");
	if (material == "")
		throw ValidatorException("Wrong material");
	if (corporealForm == "")
		throw ValidatorException("Wrong corporeal form");
	if (age < 0)
		throw ValidatorException("Wrong age");}

void Validator::validate_statue(Statue statue, std::vector<Statue> list_of_statues)
{
	for (auto &statue_in_list : list_of_statues)
		if (statue.GetWordName().compare(statue_in_list.GetWordName()) == 0)
			throw ValidatorException("Statue already exists");
}


Validator::~Validator()
{
}

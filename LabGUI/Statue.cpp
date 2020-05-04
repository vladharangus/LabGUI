#include "pch.h"
#include "Statue.h"
#include <cstring>
#include <sstream>


Statue::Statue(const std::string& wordname, const std::string& Material, const int& age, const std::string& corporealform) :
	powerWordName{ wordname }, material{ Material }, age{ age }, corporealForm{ corporealform }
{}

Statue::Statue()
{
	
}

Statue::~Statue()
{
}

void Statue::SetWordName(std::string wordname)
{
	this->powerWordName.assign(wordname);
}

void Statue::SetMaterial(std::string material)
{
	this->material.assign(material);
}

void Statue::SetAge(int age)
{
	this->age = age;
}

void Statue::SetCorporealForm(std::string corporealForm)
{
	this->corporealForm.assign(corporealForm);
}

std::string Statue::GetWordName()
{
	return this->powerWordName;
}

std::string Statue::GetMaterial()
{
	return this->material;
}

std::string Statue::GetCorporealForm()
{
	return this->corporealForm;
}

int Statue::GetAge()
{
	return this->age;
}
std::ostream & operator<<(std::ostream & Ostream, const Statue & statue)
{
	Ostream << statue.powerWordName << ", " << statue.material << ", " << statue.age << ", " << statue.corporealForm;
	return Ostream;
}

std::vector<std::string> SplitTheString(std::string string, char delimiter)
{
	std::vector <std::string> result;
	std::stringstream string_stream(string);
	std::string list_of_arguments;
	while (std::getline(string_stream, list_of_arguments, delimiter))
		result.push_back(list_of_arguments);

	return result;
}

std::istream & operator>>(std::istream & Istream, Statue & statue)
{
	std::string line;
	std::getline(Istream, line);

	std::vector<std::string> statue_arguments = SplitTheString(line, ',');
	if (statue_arguments.size() != 4)
		return Istream;
	statue_arguments[1].replace(0, 1, "");
	statue.powerWordName = statue_arguments[0];
	statue.material = statue_arguments[1];
	statue.age = std::stoi(statue_arguments[2]);
	statue_arguments[3].replace(0, 1, "");
	statue.corporealForm = statue_arguments[3];

	return Istream;
}

#include "pch.h"
#include "Service.h"
#include <iostream>


#include <algorithm>
Service::Service(Repository* repository, Repository* appretience_repository) : repository{repository}, appretience_repository{appretience_repository}
{
	this->current = -1;
}

Service::~Service()
{
}

std::string Service::AddStatue(const std::string & wordname, const std::string & material, const int & age, const std::string & corporealForm)
//Paramteres:a wordname, a material, an age and a corporeal form
//Adds in statue list the new statue
{
	try {
		Statue new_statue(wordname, material, age, corporealForm);
		std::vector<Statue> statues = this->GetStatues();
		Validator::validate_statue(new_statue, statues);
		this->repository->SaveItem(new_statue);
		return "Added";
	}
	catch (ValidatorException& exception)
	{
		return exception.GetMessage();
	}
}

void Service::UpdateStatue(const std::string & wordname, const std::string & material, const int & age, const std::string & corporealForm)
{
//Paramteres:a wordname, a material, an age and a corporeal form
//Updates a statue at a given position
	Statue new_statue(wordname, material, age, corporealForm);
	int position = this->FindPosition(new_statue.GetWordName());
	this->repository->SaveExistingItem(position, new_statue);
}

void Service::DeleteStatue(const std::string & wordname)
//Paramteres:a wordname
//Deletes the statue having the given wordname
{
	int position = this->FindPosition(wordname);
	this->repository->DeleteItem(position);
}

int Service::GetSizeofVector()
{
	return this->repository->GetSize();
}

int Service::GetSizeofVectorApprentice()
{
	return this->appretience_repository->GetSize();
}

int Service::CheckIfStatueExists(const std::string & wordname)
//Paramteres:a wordname
//Return 1 if statues exists in the list and 0 otherwise
{
	std::vector<Statue> list_of_statues = this->GetStatuesrApprentice();
	for (auto &statue : list_of_statues)
		if (statue.GetWordName().compare(wordname) == 0)
			return 1;
	return 0;
}

int Service::FindPosition(const std::string & wordname)
//Paramteres:a wordname
//Returns the position of the statue having the given wordname or -1 if it doesn't exist
{
	std::vector<Statue> list_of_statues = this->GetStatues();
	int position = 0;
	for (auto &statue : list_of_statues)
	{
		if (statue.GetWordName().compare(wordname) == 0)
			return position;
		position++;
	}
	return -1;
}

void Service::AddStatueApprentince(const std::string & wordname)
//Paramteres:a wordname
//Adds in statue list for Mode B
{
	Statue statue = FindByWordname(wordname);
	if(this->CheckIfStatueExists(wordname) == 0)
		this->appretience_repository->SaveItem(statue);
}

Statue Service::FindByWordname(const std::string & wordname)
//Paramteres:a wordname
//Returns the statue having the given wordname or a "null" statue otherwise
{
	std::vector<Statue> statues = this->GetStatues();
	for (auto &statue : statues)
		if (statue.GetWordName() == wordname)
			return statue;
	return Statue("", "", -1, "");
}

std::vector<Statue> Service::GetStatues()
{
	return this->repository->GetVector();
}

std::vector<Statue> Service::GetStatuesrApprentice()
{
	return this->appretience_repository->GetVector();
}

std::vector<Statue> Service::FilterStatuesByAge(int age)
//Paramteres:an age
//Returns a STL vector containing all the statues having the age less than the given one
{
	std::vector<Statue> statues = this->GetStatues();
	std::vector<Statue> filter_list(statues.size());
	int length = statues.size();
	auto iterator = std::copy_if(statues.begin(), statues.end(), filter_list.begin(), [age](Statue statue) {return !(statue.GetAge() >= age); });
	filter_list.resize(std::distance(filter_list.begin(), iterator));
	return filter_list;
}

std::vector<Statue> Service::FilterStatuesByAgeAndMaterial(std::string material, int age)
//Paramteres:an age and material
//Returns a STL vector containing all the statues having the age less than the given one and having the given material
{
	std::vector<Statue> statues = this->GetStatues();
	std::vector<Statue> filter_list(statues.size());
	int length = statues.size();
	auto iterator = std::copy_if(statues.begin(), statues.end(), filter_list.begin(), [age, material](Statue statue) {return !(statue.GetAge() >= age) && statue.GetMaterial() == material; });
	filter_list.resize(std::distance(filter_list.begin(), iterator));
	return filter_list;
}

Statue Service::hello_next()
{
	std::vector<Statue> list = this->GetStatues();
	if (list.size() > 0)
	{
		this->current++;
		if (this->current < list.size())
		{
			return list[this->current];
		}
		else
		{
			this->current = 0;
			return list[this->current];
		}
	}
}

/*void Service::Change_Location(std::string new_file_path)
//Paramteres: a string representing the new file location
//From now on, the commands will work with statues from the new location
{
	this->repository.ChangePath(new_file_path);
}

std::string Service::GetPathModeB()
{
	return this->appretience_repository.GetPath();
}

void Service::Change_LocationModeB(std::string new_path)
{
	this->appretience_repository.ChangePath(new_path);
}*/

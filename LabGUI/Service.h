#pragma once
#include "Repository.h"
#include "FileRepository.h"
#include "CVS_HTMLRepository.h"
#include "ValidatorException.h"
#include "Validator.h"
#include <algorithm>
class Service
{
private:
	Repository* repository; 
	Repository* appretience_repository;
	int current;


public:
	Service(Repository* repository, Repository* appetrience_repository);
	~Service();
	std::string AddStatue(const std::string& wordname, const std::string& material, const int& age, const std::string& corporealForm);
	void UpdateStatue(const std::string& wordname, const std::string& material, const int& age, const std::string& corporealForm);
	void DeleteStatue(const std::string& wordname);
	int GetSizeofVector();
	int GetSizeofVectorApprentice();
	int CheckIfStatueExists(const std::string& wordname);
	int FindPosition(const std::string& wordname);
	void AddStatueApprentince(const std::string& wordname);
	Statue FindByWordname(const std::string& wordname);
	Statue hello_next();
	std::vector<Statue> GetStatues();
	std::vector<Statue> GetStatuesrApprentice();
	std::vector<Statue> FilterStatuesByAge(int age);
	std::vector<Statue> FilterStatuesByAgeAndMaterial(std::string material, int age);
	
	//void Change_Location(std::string new_file_path);
	//std::string GetPathModeB();
	//void Change_LocationModeB(std::string new_path);
};
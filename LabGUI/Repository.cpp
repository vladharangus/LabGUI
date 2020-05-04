#include "pch.h"
#include "Repository.h"




Repository::Repository(std::vector<Statue>& list) : list_of_statues{ list }{
}

void Repository::SaveItem(Statue statue)
{
	this->list_of_statues.push_back(statue);
}

void Repository::SaveExistingItem(int position, Statue statue)
{
	this->list_of_statues[position] = statue;
}

int Repository::GetSize()
{
	return this->list_of_statues.size();
}

void Repository::DeleteItem(int position)
{
	this->list_of_statues.erase(this->list_of_statues.begin() + position);
}

std::vector<Statue> Repository::GetVector()
{
	return this->list_of_statues;
}


Repository::~Repository()
{

}

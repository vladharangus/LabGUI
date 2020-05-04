#pragma once
#include "Statue.h"
#include "vector"
class Repository
{
protected:
	std::vector<Statue>& list_of_statues;
public:
	Repository(std::vector<Statue>& list);
	virtual void SaveItem(Statue statue);
	virtual void SaveExistingItem(int position, Statue statue);
	int GetSize();
	virtual void DeleteItem(int position);
	virtual std::vector<Statue> GetVector();
	~Repository();
};
#pragma once
#include "Repository.h"
#include <fstream>
#include <iostream>
class CSV_HTMLRepository : public Repository
{
private:
	std::string file_path;
public:
	CSV_HTMLRepository(std::vector<Statue>& list);
	void WriteInCSVFile();
	void WriteInHTMLFile();
	void SaveItem(Statue statue) override;
	void StoreInFile();
	std::string GetPath();
	void ChangePath(std::string new_path);
	~CSV_HTMLRepository();
};


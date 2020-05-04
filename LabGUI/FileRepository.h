#pragma once
#include "Repository.h"
#include <fstream>
#include <iostream>
class FileRepository : public Repository
{
private:
	std::string file_path;
public:
	FileRepository(const std::string& file_path, std::vector<Statue>& list);
	void WriteInFile();
	void ReadFromFile();
	void SaveItem(Statue statue) override;
	void SaveExistingItem(int position, Statue statue) override;
	void DeleteItem(int position) override;
	void ChangePath(std::string new_path);
	~FileRepository();
};
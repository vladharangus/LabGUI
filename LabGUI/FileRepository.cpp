#include "pch.h"
#include "FileRepository.h"

FileRepository::FileRepository(const std::string & file_path, std::vector<Statue>& list) : Repository(list)
{
	this->file_path.assign(file_path);
	this->ReadFromFile();
}

void FileRepository::WriteInFile()
{
	std::ofstream myfile;
	myfile.open(this->file_path);
	if (myfile.is_open())
	{
			for (auto statue : this->list_of_statues)
			{
				myfile << statue;
				myfile << "\n";
			}
		myfile.close();
	}
}

void FileRepository::ReadFromFile()
{
	std::string command;
	std::ifstream myfile;
	myfile.open(this->file_path, std::ios::app);
	Statue statue{};
	if (myfile.is_open())
	{
		while (myfile >> statue)
		{
			this->list_of_statues.push_back(statue);
		}
	}
	myfile.close();
}

void FileRepository::SaveItem(Statue statue)
{
	Repository::SaveItem(statue);
	this->WriteInFile();
}

void FileRepository::SaveExistingItem(int position, Statue statue)
{
	Repository::SaveExistingItem(position, statue);
	this->WriteInFile();
}

void FileRepository::DeleteItem(int position)
{
	Repository::DeleteItem(position);
	this->WriteInFile();
}
void FileRepository::ChangePath(std::string new_path)
{
	this->file_path.assign(new_path);
	this->list_of_statues.clear();
	this->ReadFromFile();
}
FileRepository::~FileRepository()
{
}

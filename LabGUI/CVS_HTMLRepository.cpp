#include "pch.h"
#include "CVS_HTMLRepository.h"



CSV_HTMLRepository::CSV_HTMLRepository(std::vector<Statue>& list) : Repository(list)
{
	this->file_path.assign("modeB.csv");
}

void CSV_HTMLRepository::WriteInCSVFile()
{
	std::ofstream myfile;
	myfile.open(this->file_path, std::ios::app);
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

void CSV_HTMLRepository::WriteInHTMLFile()
{
	std::ofstream myfile;
	myfile.open(this->file_path, std::ios::app);
	if (myfile.is_open())
	{
		myfile << "<!DOCTYPE html>\n";
		myfile << "<html>\n";
		myfile << " <head>\n";
		myfile << " <title>Statues</title>\n";
		myfile << "</head>\n";
		myfile << "<body>\n";
		myfile << " <table border=1>\n";
		myfile << "<tr>\n";
		myfile << "<td>" << "Word Name" << "</td>\n";
		myfile << "<td>" << "Material" << "</td>\n";
		myfile << "<td>" << "Age" << "</td>\n";
		myfile << "<td>" << "Corporeal Form" << "</td>\n";
		for (auto statue : this->list_of_statues)
		{
			myfile << "<tr>\n";
			myfile << "<td>" << statue.GetWordName() << "</td>\n";
			myfile << "<td>" << statue.GetMaterial() << "</td>\n";
			myfile << "<td>" << std::to_string(statue.GetAge()) << "</td>\n";
			myfile << "<td>" << statue.GetCorporealForm() << "</td>\n";
		}
		myfile << "</table>\n </body>\n </html>";
		myfile.close();
	}
}

void CSV_HTMLRepository::SaveItem(Statue statue)
{
	Repository::SaveItem(statue);
	this->StoreInFile();
}

void CSV_HTMLRepository::StoreInFile()
{
	int position_of_dot = this->file_path.find('.');
	if (this->file_path[position_of_dot + 1] == 'c')
		this->WriteInCSVFile();
	if (this->file_path[position_of_dot + 1] == 'h')
		this->WriteInHTMLFile();
}

std::string CSV_HTMLRepository::GetPath()
{
	return this->file_path;
}

void CSV_HTMLRepository::ChangePath(std::string new_path)
{
	this->file_path.assign(new_path);
}


CSV_HTMLRepository::~CSV_HTMLRepository()
{
}

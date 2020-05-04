#pragma once
#include <string>
#include <vector>
class Statue
{
private:
	std::string powerWordName;
	std::string material;
	int age = -1;
	std::string corporealForm;	
public:
	Statue(const std::string& wordname, const std::string& material, const int& age, const std::string& corporealForm);
	Statue();
	~Statue();
	void SetWordName(std::string wordname);
	void SetMaterial(std::string material);
	void SetAge(int age);
	void SetCorporealForm(std::string corporealForm);
	std::string GetWordName();
	std::string GetMaterial();
	std::string GetCorporealForm();
	int GetAge();
	friend std::ostream& operator<<(std::ostream& os, const Statue& statue);
	friend std::istream& operator>>(std::istream& is, Statue& statue);
};
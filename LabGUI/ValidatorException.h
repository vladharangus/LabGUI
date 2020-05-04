#pragma once
#include <string>
class ValidatorException
{
private:
	std::string message;
public:
	ValidatorException(const std::string message);
	std::string GetMessage() const;
	~ValidatorException();
};


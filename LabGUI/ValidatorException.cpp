#include "pch.h"
#include "ValidatorException.h"

ValidatorException::ValidatorException(const std::string message) 
{
	this->message.assign(message);
}

std::string ValidatorException::GetMessage() const
{
	return this->message;
}

ValidatorException::~ValidatorException()
{
}

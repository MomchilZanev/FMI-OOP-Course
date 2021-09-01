#include "Error.hpp"

Error::Error()
{
	this->message = nullptr;
	this->type = ErrorType::None;
}

Error::Error(const Error& rhs) : type(rhs.getType())
{
	this->message = copy(rhs.getMessage());
}

Error::~Error()
{
	delete[] this->message;
}

Error& Error::operator=(const Error& rhs)
{
	if (this != &rhs)
	{		
		this->type = rhs.getType();
		delete[] this->message;
		this->message = copy(rhs.getMessage());
	}
	return *this;
}

bool Error::hasMessage() const
{
	return this->message != nullptr;
}

const char* Error::getMessage() const
{
	return this->message;
}

ErrorType Error::getType() const
{
	return this->type;
}

Error Error::newNone()
{
	Error none;
	return none;
}

Error Error::newBuildFailed(const char* message)
{
	Error buildFailed;
	buildFailed.type = ErrorType::BuildFailed;
	buildFailed.message = copy(message);
	return buildFailed;
}

Error Error::newWarning(const char* message)
{
	Error warning;
	warning.type = ErrorType::Warning;
	warning.message = copy(message);
	return warning;
}

Error Error::newFailedAssertion(const char* message)
{
	Error failedAssertion;
	failedAssertion.type = ErrorType::FailedAssertion;
	failedAssertion.message = copy(message);
	return failedAssertion;
}

char* Error::copy(const char* original)
{
	if (original == nullptr)
	{
		return nullptr;
	}
	const int arraySize = strlen(original) + 1;
	char* newCopy = new char[arraySize];
	strcpy_s(newCopy, arraySize, original);
	return newCopy;
}
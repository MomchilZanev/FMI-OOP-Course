#pragma once
#include <string>

#include "Error.hpp"

class TestCase
{
public:
    TestCase(const std::string& name = "", const Error& error = Error::newNone());

    std::string getName() const;

    bool isPassing() const;
    bool hasError() const;
    ErrorType getErrorType() const;
    std::string getErrorMessage() const;
private:
    std::string name;
    Error error;
};
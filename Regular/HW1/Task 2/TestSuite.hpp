#pragma once
#include <string>
#include <vector>

#include "TestCase.hpp"

class TestSuite 
{
public:
    TestSuite(std::string name);

    
    std::vector<TestCase> filterPassing() const;
    std::vector<TestCase> filterFailing() const;
    std::vector<TestCase> filterByErrorType(ErrorType) const;
    std::string getName() const;

    void setName(const std::string& newName);
    void add(const TestCase&);
    void removeByErrorType(ErrorType);
private:
    std::string name;
    std::vector<TestCase> testCases;
};
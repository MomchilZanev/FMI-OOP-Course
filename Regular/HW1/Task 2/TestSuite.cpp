#include "TestSuite.hpp"

TestSuite::TestSuite(std::string name) : name(name)
{ }

void TestSuite::add(const TestCase& testCase)
{
	this->testCases.push_back(testCase);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase> passing;
	for (int i = 0; i < this->testCases.size(); i++)
	{
		if (this->testCases[i].isPassing())
		{
			passing.push_back(this->testCases[i]);
		}
	}
	return passing;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase> failing;
	for (int i = 0; i < this->testCases.size(); i++)
	{
		if (!this->testCases[i].isPassing())
		{
			failing.push_back(this->testCases[i]);
		}
	}
	return failing;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType errorType) const
{
	std::vector<TestCase> filtered;
	for (int i = 0; i < this->testCases.size(); i++)
	{
		if (this->testCases[i].getErrorType() == errorType)
		{
			filtered.push_back(this->testCases[i]);
		}
	}
	return filtered;
}

void TestSuite::removeByErrorType(ErrorType errorType)
{
	for (int i = 0; i < this->testCases.size();)
	{
		if (this->testCases[i].getErrorType() == errorType)
		{
			this->testCases.erase(this->testCases.begin() + i);
		}
		else 
		{
			i++;
		}
	}
}

std::string TestSuite::getName() const
{
	return this->name;
}

void TestSuite::setName(const std::string& newName)
{
	this->name = newName;
}
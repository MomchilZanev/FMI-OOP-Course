#pragma once
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <string>

class TeamLead;

class Developer
{
public:
	Developer(const std::string& name);

	void setInitialSalary(const double amount);	
	void setSalary(const double amount);
	void setTeamLead(TeamLead* teamLead);

	void sendLeavingRequest();
	void sendPromotionRequest(const double amount);

	std::string getName() const;
	double getSalary() const;
	const TeamLead* getTeamLead() const;
protected:
	template <typename T>
	T getMax(T num1, T num2);
	template <typename T>
	T getAbs(T num);
private:
	std::string name;
	double salary;
	TeamLead* teamLead;
};

template<typename T>
T Developer::getMax(T num1, T num2)
{
	return num1 >= num2 ? num1 : num2;
}

template<typename T>
T Developer::getAbs(T num)
{
	return num >= 0 ? num : -num;
}
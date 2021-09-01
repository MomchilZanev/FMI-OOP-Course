#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string& name)
	:name(name), salary(0), teamLead(nullptr)
{ }

void Developer::setInitialSalary(const double amount)
{
	if (this->getSalary() == 0)
	{
		this->setSalary(amount);
	}
}

void Developer::setSalary(const double amount)
{
	this->salary = this->getMax<double>(amount, 0.0);
}

void Developer::setTeamLead(TeamLead* teamLead)
{
	this->teamLead = teamLead;
}

void Developer::sendLeavingRequest()
{
	if (this->teamLead != nullptr)
	{
		this->teamLead->addLeavingRequest(LeavingRequest(this->getName()));
	}
}

void Developer::sendPromotionRequest(const double amount)
{
	if (this->teamLead != nullptr)
	{
		this->teamLead->addPromotionRequest(PromotionRequest(this->getName(), this->getAbs<double>(amount)));
	}	
}

std::string Developer::getName() const
{
	return this->name;
}

double Developer::getSalary() const
{
	return this->salary;
}

const TeamLead* Developer::getTeamLead() const
{
	return this->teamLead;
}
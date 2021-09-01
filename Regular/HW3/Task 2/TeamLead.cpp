#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, const double salary)
	:Developer(name)
{
	this->setInitialSalary(salary);
	this->setTeamLead(this);
}

std::vector<Developer*> TeamLead::getTeam()
{
	return this->team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, const double salary)
{
	if (developer != nullptr)
	{
		this->team.push_back(developer);
		developer->setInitialSalary(salary);
		developer->setTeamLead(this);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	for (int i = this->team.size() - 1; i >= 0; i--)
	{
		if (this->team[i]->getName() == name)
		{
			this->team[i]->setTeamLead(nullptr);
			//this->team[i]->setSalary(0);
			this->team.erase(this->team.begin() + i);
			return;
		}
	}
}

void TeamLead::increaseDeveloperSalary(const std::string& name, const double amount)
{
	for (unsigned i = 0; i < this->team.size(); i++)
	{
		if (this->team[i]->getName() == name)
		{
			this->team[i]->setSalary(this->team[i]->getSalary() + this->getAbs<double>(amount));
		}
	}
}

void TeamLead::increaseTeamSalariesBy(const double amount)
{
	for (unsigned i = 0; i < this->team.size(); i++)
	{
		this->team[i]->setSalary(this->team[i]->getSalary() + this->getAbs<double>(amount));
	}
}

void TeamLead::decreaseTeamSalariesBy(const double amount)
{
	for (unsigned i = 0; i < this->team.size(); i++)
	{
		this->team[i]->setSalary(this->team[i]->getSalary() - this->getAbs<double>(amount));
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	this->leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (unsigned i = 0; i < this->leavingRequests.size(); i++)
	{
		this->removeDeveloperFromTeam(this->leavingRequests[i].getSender());
	}
	this->leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (unsigned i = 0; i < this->promotionRequests.size(); i++)
	{
		this->increaseDeveloperSalary(this->promotionRequests[i].getSender(), this->promotionRequests[i].getAmount());
	}
	this->promotionRequests.clear();
}
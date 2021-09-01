#pragma once
#include <vector>
#include "Developer.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead : public Developer
{
public:
	TeamLead(const std::string& name, const double salary);

	std::vector<Developer*> getTeam();
	void addDeveloperToTeam(Developer* developer, const double salary);
	void removeDeveloperFromTeam(const std::string& name);
	void increaseDeveloperSalary(const std::string& name, const double amount);
	void increaseTeamSalariesBy(const double amount);
	void decreaseTeamSalariesBy(const double amount);
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();
private:
	std::vector<Developer*> team;
	std::vector<LeavingRequest> leavingRequests;
	std::vector<PromotionRequest> promotionRequests;
};
#pragma once
#include "Request.hpp"

class PromotionRequest : public Request
{
public:
	static const std::string PROMOTION_MSG;

	PromotionRequest(const std::string& sender, const double amount);

	double getAmount() const;
private:
	double amount;
};
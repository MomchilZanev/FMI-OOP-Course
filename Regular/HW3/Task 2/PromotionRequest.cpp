#include "PromotionRequest.hpp"

PromotionRequest::PromotionRequest(const std::string& sender, const double amount)
    :Request(PROMOTION_MSG, sender), amount(amount)
{ }

double PromotionRequest::getAmount() const
{
    return this->amount;
}

const std::string PromotionRequest::PROMOTION_MSG = "I want a raise!";
#pragma once
#include "Subscriber.hpp"

class PeriodicSampler : public Subscriber
{
public:
	PeriodicSampler(const std::string& id, const size_t& period);

	void signal(const Message& message) override;
	int read() const override;
	Subscriber* getCopy() const override;

	const size_t period;
private:
	unsigned counter;
};

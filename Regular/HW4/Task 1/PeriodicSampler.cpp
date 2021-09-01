#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string& id, const size_t& period)
	:Subscriber(id), period(period), counter(0)
{ }

void PeriodicSampler::signal(const Message& message)
{
	if (this->counter % this->period == 0)
	{
		Subscriber::signal(message);
	}
	this->counter++;
}

int PeriodicSampler::read() const
{
	return this->messages.empty() ? EMPTY_DEF : this->messages.back().data;
}

Subscriber* PeriodicSampler::getCopy() const
{
	return new PeriodicSampler(*this);
}
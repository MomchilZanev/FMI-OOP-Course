#include "Counter.hpp"

Counter::Counter(const int initialValue, const unsigned step)
	:value(initialValue), step(step)
{ }

void Counter::increment()
{
	this->value += this->getStep();
}

int Counter::getTotal() const
{
	return this->value;
}

int Counter::getStep() const
{
	return this->step;
}
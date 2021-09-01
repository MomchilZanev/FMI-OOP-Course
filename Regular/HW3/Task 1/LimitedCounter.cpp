#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(const int max, const int initialValue, const unsigned step)
	:Counter(initialValue, step), max(max)
{ }

void LimitedCounter::increment()
{
	if (this->getTotal() + this->getStep() <= this->getMax())
	{
		Counter::increment();
	}
}

int LimitedCounter::getMax() const
{
    return this->max;
}
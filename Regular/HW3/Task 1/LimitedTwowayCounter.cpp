#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(const int min, const int max, const int initialValue, const unsigned step)
    :Counter(initialValue, step), LimitedCounter(max, initialValue, step), TwowayCounter(initialValue, step), min(min)
{ }

void LimitedTwowayCounter::increment()
{
    LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement()
{
    if (this->getTotal() - this->getStep() >= this->getMin())
    {
        TwowayCounter::decrement();
    }
}

int LimitedTwowayCounter::getMin() const
{
    return this->min;
}
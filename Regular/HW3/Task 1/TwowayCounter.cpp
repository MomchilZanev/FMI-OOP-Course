#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter(const int initialValue, const unsigned step)
	:Counter(initialValue, step)
{ }

void TwowayCounter::decrement()
{
	this->value -= this->getStep();
}
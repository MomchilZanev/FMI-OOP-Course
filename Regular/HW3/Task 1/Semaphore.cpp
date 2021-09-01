#include "Semaphore.hpp"

Semaphore::Semaphore(const bool toggle)
	:Counter(toggle ? 1 : DEFAULT_INITIAL_VALUE, DEFAULT_STEP), 
	LimitedTwowayCounter(SEMAPHORE_MIN, SEMAPHORE_MAX, toggle ? 1 : DEFAULT_INITIAL_VALUE, DEFAULT_STEP)
{ }

bool Semaphore::isAvailable() const
{
	return this->getTotal() > 0;
}

void Semaphore::wait()
{
	LimitedTwowayCounter::decrement();
}

void Semaphore::signal()
{
	LimitedTwowayCounter::increment();
}
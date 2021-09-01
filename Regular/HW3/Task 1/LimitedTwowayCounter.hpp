#pragma once
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class  LimitedTwowayCounter : public LimitedCounter, public TwowayCounter
{
public:
	LimitedTwowayCounter(const int min, const int max, const int initialValue = DEFAULT_INITIAL_VALUE, const unsigned step = DEFAULT_STEP);

	void increment();
	void decrement();
	int getMin() const;
protected:
	const int min;
};
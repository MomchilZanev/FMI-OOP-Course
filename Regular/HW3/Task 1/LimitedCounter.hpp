#pragma once
#include "Counter.hpp"

class LimitedCounter : public virtual Counter
{
public:
	LimitedCounter(const int max, const int initialValue = DEFAULT_INITIAL_VALUE, const unsigned step = DEFAULT_STEP);

	void increment();
	int getMax() const;
protected:
	const int max;
};
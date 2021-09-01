#pragma once
#include "Counter.hpp"

class TwowayCounter : public virtual Counter
{
public:
	TwowayCounter(const int initialValue = DEFAULT_INITIAL_VALUE, const unsigned step = DEFAULT_STEP);

	void decrement();
};
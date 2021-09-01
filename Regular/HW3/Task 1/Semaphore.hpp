#pragma once
#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter
{
public:
	static const int SEMAPHORE_MIN = 0;
	static const int SEMAPHORE_MAX = 1;

	Semaphore(const bool toggle = false);

	bool isAvailable() const;
	void wait();
	void signal();
};
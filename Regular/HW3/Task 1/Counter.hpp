#pragma once

class Counter
{
public:
	static const int DEFAULT_INITIAL_VALUE = 0;
	static const unsigned DEFAULT_STEP = 1;

	Counter(const int initialValue = DEFAULT_INITIAL_VALUE, const unsigned step = DEFAULT_STEP);

	void increment();
	int getTotal() const;
	int getStep() const;
protected:
	int value;
	const unsigned step;
};
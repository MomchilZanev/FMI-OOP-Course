#pragma once
#include <iostream>
#include "Helpers.hpp"

class Money
{
public:
	Money();
	Money(const int silver, const int gold);

	Money& operator=(const Money& rhs);

	void print() const;	
	void clearAll();
	void add(const Money& money);
	void remove(const Money& money);

	bool isEmpty() const;
	bool isFull() const;
	unsigned int slotsOccupied() const;
	unsigned int getSilver() const;
	unsigned int getGold() const;
	const int MAX_SLOTS = 1;
private:
	void convertCurrency();

	unsigned int silver;
	unsigned int gold;
};

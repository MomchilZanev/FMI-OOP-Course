#pragma once
#include <iostream>
#include "Helpers.hpp"

class Materials
{
public:
	Materials();
	Materials(const int herbs, const int ores, const int cloth, const int essence);

	Materials& operator=(const Materials& rhs);
	
	void print() const;	
	void clearAll();
	void add(const Materials& materials);
	void remove(const Materials& materials);

	bool isEmpty() const;
	bool isFull() const;
	unsigned int slotsOccupied() const;
	unsigned int getHerbs() const;
	unsigned int getOres() const;
	unsigned int getCloth() const;
	unsigned int getEssence() const;
	const int MAX_SLOTS = 16;
private:
	const int MAX_ESSENCE_IN_SLOT = 10;
	const int MAX_OTHER_IN_SLOT = 20;
	unsigned int getSlotsOccupiedByItem(const unsigned int quantity, const unsigned int maxOfInSlot) const;

	unsigned int herbs;
	unsigned int ores;
	unsigned int cloth;
	unsigned int essence;
};
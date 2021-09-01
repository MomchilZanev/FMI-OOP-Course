#include <iostream>
#include <cstring>
#include "MonsterCard.hpp"
using namespace std;

MonsterCard::MonsterCard()
{
	setName("");
	setAttackPoints(0);
	setDefensePoints(0);
}

MonsterCard::MonsterCard(const char name[NAME_MAX_SIZE], const unsigned int attackPoints, const unsigned int defensePoints)
{
	setName(name);
	setAttackPoints(attackPoints);
	setDefensePoints(defensePoints);
	this->initialized = true;
}

void MonsterCard::setName(const char name[NAME_MAX_SIZE])
{
	strcpy_s(this->name, NAME_MAX_SIZE, name);
}

void MonsterCard::setAttackPoints(const unsigned int attackPoints)
{
	this->attackPoints = attackPoints;
}

void MonsterCard::setDefensePoints(const unsigned int defensePoints)
{
	this->defensePoints = defensePoints;
}

const char* MonsterCard::getName() const
{
	return name;
}

unsigned int MonsterCard::getAttackPoints() const
{
	return this->attackPoints;
}

unsigned int MonsterCard::getDefensePoints() const
{
	return this->defensePoints;
}

bool MonsterCard::isInitialized() const
{
	return this->initialized;
}
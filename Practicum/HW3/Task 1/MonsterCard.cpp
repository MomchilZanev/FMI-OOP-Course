#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const std::string& name, const std::string& effect, const int attackPoints, const int defensePoints)
	:Card(name, effect), attackPoints(getAbs<int>(attackPoints)), defensePoints(getAbs<int>(defensePoints))
{ }

std::string MonsterCard::printMonsterCard() const
{
	std::string result;

	result.append(this->printCard());
	result.append("|");
	result.append(this->printPoints());

	return result;
}

unsigned int MonsterCard::getAttackPoints() const
{
	return this->attackPoints;
}

unsigned int MonsterCard::getDefensePoints() const
{
	return this->defensePoints;
}

std::string MonsterCard::printPoints() const
{
	std::string result;

	result.append(std::to_string(this->getAttackPoints()));
	result.append("|");
	result.append(std::to_string(this->getDefensePoints()));

	return result;
}

void MonsterCard::changeAttackPoints(const int attackPoints)
{
	this->attackPoints = getAbs<int>(attackPoints);
	
}

void MonsterCard::changeDefensePoints(const int defensePoints)
{
	this->defensePoints = getAbs<int>(defensePoints);
}
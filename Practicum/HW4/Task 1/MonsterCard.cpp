#include "MonsterCard.hpp"

MonsterCard::MonsterCard(const std::string& name, const std::string& effect, const int rarity, const int attackPoints, const int defensePoints)
	:Card(name, effect, rarity)
{
	this->changeAttackPoints(attackPoints);
	this->changeDefensePoints(defensePoints);
}

void MonsterCard::changeAttackPoints(const int attackPoints)
{
	this->attackPoints = getMax<int>(attackPoints, 0);
	
}

void MonsterCard::changeDefensePoints(const int defensePoints)
{
	this->defensePoints = getMax<int>(defensePoints, 0);
}

std::string MonsterCard::printCard() const
{
	std::string result;

	result.append(this->printBaseInfo());
	result.append("|");
	result.append(this->printPoints());

	return result;
}

unsigned MonsterCard::getAttackPoints() const
{
	return this->attackPoints;
}

unsigned MonsterCard::getDefensePoints() const
{
	return this->defensePoints;
}

Card* MonsterCard::getCopy() const
{
	return new MonsterCard(*this);
}

std::string MonsterCard::printPoints() const
{
	std::string result;

	result.append(std::to_string(this->getAttackPoints()));
	result.append("|");
	result.append(std::to_string(this->getDefensePoints()));

	return result;
}
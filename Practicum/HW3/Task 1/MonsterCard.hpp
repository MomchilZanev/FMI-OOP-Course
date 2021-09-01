#pragma once
#include "Card.hpp"
#include "Helpers.hpp"

class MonsterCard : virtual public Card
{
public:
	MonsterCard() = default;
	MonsterCard(const std::string& name, const std::string& effect, const int attackPoints, const int defensePoints);

	void changeAttackPoints(const int attackPoints);
	void changeDefensePoints(const int defensePoints);

	std::string printMonsterCard() const;
	unsigned int getAttackPoints() const;
	unsigned int getDefensePoints() const;
protected:
	std::string printPoints() const;
private:
	unsigned int attackPoints;
	unsigned int defensePoints;
};
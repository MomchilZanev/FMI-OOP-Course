#pragma once
#include "Card.hpp"

class MonsterCard : virtual public Card
{
public:
	MonsterCard() = default;
	MonsterCard(const std::string& name, const std::string& effect, const int rarity, const int attackPoints, const int defensePoints);

	void changeAttackPoints(const int attackPoints);
	void changeDefensePoints(const int defensePoints);

	std::string printCard() const override;
	unsigned getAttackPoints() const;
	unsigned getDefensePoints() const;

	Card* getCopy() const override;
protected:
	std::string printPoints() const;
private:
	unsigned attackPoints;
	unsigned defensePoints;
};
#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard
{
public:
	PendulumCard();
	PendulumCard(const std::string& name, const std::string& effect, const int rarity, const int attackPoints, const int defensePoints, const int pendulumScale, const CardType type);
	PendulumCard(const PendulumCard& rhs);
	PendulumCard& operator=(const PendulumCard& rhs);

	void changePendulumScale(const int pendulumScale);

	std::string printCard() const override;
	unsigned getPendulumScale() const;

	Card* getCopy() const override;
private:
	static const int PENDULUM_SCALE_MIN = 1;
	static const int PENDULUM_SCALE_MAX = 13;

	unsigned pendulumScale;
};
#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard
{
public:
	const int PENDULUM_SCALE_MIN = 1;
	const int PENDULUM_SCALE_MAX = 13;

	PendulumCard();
	PendulumCard(
		const std::string& name,
		const std::string& effect,
		const unsigned int attackPoints,
		const unsigned int defensePoints,
		const int pendulumScale,
		const CardType type);
	PendulumCard(const PendulumCard& rhs);
	PendulumCard& operator=(const PendulumCard& rhs);

	void changePendulumScale(const int pendulumScale);

	std::string printPendulumCard() const;
	int getPendulumScale() const;	
private:
	int pendulumScale;
};
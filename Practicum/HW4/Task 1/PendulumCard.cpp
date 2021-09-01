#include "PendulumCard.hpp"

PendulumCard::PendulumCard()
	:Card("", "", 0), MonsterCard("", "", 0, 0, 0), MagicCard("", "", 0, CardType::BUFF), pendulumScale(PENDULUM_SCALE_MIN)
{ }

PendulumCard::PendulumCard(const std::string& name,
	const std::string& effect, const int rarity, const int attackPoints, 
	const int defensePoints, const int pendulumScale, const CardType type)
	:Card(name, effect, rarity), MonsterCard(name, effect, rarity, attackPoints, defensePoints), MagicCard(name, effect, rarity, type)
{
	this->changePendulumScale(pendulumScale);
}

PendulumCard::PendulumCard(const PendulumCard& rhs)
	:Card(rhs), MonsterCard(rhs), MagicCard(rhs), pendulumScale(rhs.getPendulumScale())
{ }

PendulumCard& PendulumCard::operator=(const PendulumCard& rhs)
{
	if (this != &rhs)
	{
		MonsterCard::operator=(rhs);
		MagicCard::operator=(rhs);
		this->changePendulumScale(rhs.getPendulumScale());
	}
	return *this;
}

void PendulumCard::changePendulumScale(const int pendulumScale)
{
	if (isBetweenOrEqual<int>(pendulumScale, PENDULUM_SCALE_MIN, PENDULUM_SCALE_MAX))
	{
		this->pendulumScale = pendulumScale;
		return;
	}
	
	this->pendulumScale = PENDULUM_SCALE_MIN;
}

std::string PendulumCard::printCard() const
{
	std::string result;

	result.append(this->printBaseInfo());
	result.append("|");
	result.append(this->printPoints());
	result.append("|");
	result.append(std::to_string(this->getPendulumScale()));
	result.append("|");
	result.append(this->printType());

	return result;
}

unsigned PendulumCard::getPendulumScale() const
{
	return this->pendulumScale;
}

Card* PendulumCard::getCopy() const
{
	return new PendulumCard(*this);
}
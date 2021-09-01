#include "PendulumCard.hpp"

PendulumCard::PendulumCard()
	:Card("", ""), MonsterCard("", "", 0, 0), MagicCard("", "", CardType::BUFF), pendulumScale(PENDULUM_SCALE_MIN)
{ }

PendulumCard::PendulumCard(const std::string& name,
	const std::string& effect, const unsigned int attackPoints, 
	const unsigned int defensePoints, const int pendulumScale, const CardType type)
	:Card(name, effect), MonsterCard(name, effect, attackPoints, defensePoints), MagicCard(name, effect, type)
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

std::string PendulumCard::printPendulumCard() const
{
	std::string result;

	result.append(this->printCard());
	result.append("|");
	result.append(this->printPoints());
	result.append("|");
	result.append(std::to_string(this->getPendulumScale()));
	result.append("|");
	result.append(this->printType());

	return result;
}

int PendulumCard::getPendulumScale() const
{
	return this->pendulumScale;
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
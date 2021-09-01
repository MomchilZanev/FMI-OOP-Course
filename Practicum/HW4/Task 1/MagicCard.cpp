#include "MagicCard.hpp"

MagicCard::MagicCard(const std::string& name, const std::string& effect, const int rarity, const CardType type)
	:Card(name, effect, rarity), type(type)
{ }

void MagicCard::changeType(const CardType type)
{
	this->type = type;
}

std::string MagicCard::printCard() const
{
	std::string result;

	result.append(this->printBaseInfo());
	result.append("|");
	result.append(this->printType());

	return result;
}

CardType MagicCard::getType() const
{
	return this->type;
}

Card* MagicCard::getCopy() const
{
	return new MagicCard(*this);
}

std::string MagicCard::printType() const
{
	std::string result;

	switch (this->getType())
	{
	case CardType::TRAP:
		result.append("TRAP");
		break;
	case CardType::BUFF:
		result.append("BUFF");
		break;
	case CardType::SPELL:
		result.append("SPELL");
		break;
	}

	return result;
}
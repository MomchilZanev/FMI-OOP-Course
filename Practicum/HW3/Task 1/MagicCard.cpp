#include "MagicCard.hpp"

MagicCard::MagicCard(const std::string& name, const std::string& effect, const CardType type)
	:Card(name, effect), type(type)
{ }

std::string MagicCard::printMagicCard() const
{
	std::string result;

	result.append(this->printCard());
	result.append("|");
	result.append(this->printType());

	return result;
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

void MagicCard::changeType(const CardType type)
{
	this->type = type;
}

const CardType MagicCard::getType() const
{
	return this->type;
}
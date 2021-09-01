#include "Card.hpp"

Card::Card(const std::string& name, const std::string& effect)
	:name(name), effect(effect)
{ }

void Card::changeName(const std::string& name)
{
	this->name = name;
}

void Card::changeEffect(const std::string& effect)
{
	this->effect = effect;
}

std::string Card::printCard() const
{
	std::string result;

	result.append(this->getName());
	result.append("|");
	result.append(this->getEffect());

	return result;
}

std::string Card::getName() const
{
	return this->name;
}

std::string Card::getEffect() const
{
	return this->effect;
}
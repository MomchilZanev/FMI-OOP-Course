#include "Card.hpp"

Card::Card(const std::string& name, const std::string& effect, const int rarity)
	:name(name), effect(effect)
{
	this->changeRarity(rarity);
}

bool Card::operator<(const Card& rhs)
{
	return this->getRarity() < rhs.getRarity();
}

bool Card::operator>(const Card& rhs)
{
	return this->getRarity() > rhs.getRarity();
}

void Card::changeName(const std::string& name)
{
	this->name = name;
}

void Card::changeEffect(const std::string& effect)
{
	this->effect = effect;
}

void Card::changeRarity(const int rarity)
{
	this->rarity = getMax<int>(rarity, 0);
}

std::string Card::getName() const
{
	return this->name;
}

std::string Card::getEffect() const
{
	return this->effect;
}

unsigned Card::getRarity() const
{
	return this->rarity;
}

std::string Card::printBaseInfo() const
{
	std::string result;

	result.append(this->getName());
	result.append("|");
	result.append(this->getEffect());
	result.append("|");
	result.append(std::to_string(this->getRarity()));

	return result;
}
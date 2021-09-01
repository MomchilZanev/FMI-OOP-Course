#include "Deck.hpp"

const std::string invalidIndexError = "Invalid index given.";

Deck::Deck(const std::string name)
	:name(name)
{ }

void Deck::changeName(const std::string& name)
{
	this->name = name;
}

void Deck::addMonsterCard(const MonsterCard& card)
{
	this->monsterCards.push_back(card);
}

void Deck::addMagicCard(const MagicCard& card)
{
	this->magicCards.push_back(card);
}

void Deck::addPendulumCard(const PendulumCard& card)
{
	this->pendulumCards.push_back(card);
}

bool Deck::changeMonsterCard(const int index, const MonsterCard& card)
{
	if (index < 0 || index >= this->getMonsterCardsCount())
	{
		std::cout << invalidIndexError << std::endl;
		return false;
	}

	this->monsterCards[index] = card;
	return true;
}

bool Deck::changeMagicCard(const int index, const MagicCard& card)
{
	if (index < 0 || index >= this->getMagicCardsCount())
	{
		std::cout << invalidIndexError << std::endl;
		return false;
	}

	this->magicCards[index] = card;
	return true;
}

bool Deck::changePendulumCard(const int index, const PendulumCard& card)
{
	if (index < 0 || index >= this->getPendulumCardsCount())
	{
		std::cout << invalidIndexError << std::endl;
		return false;
	}

	this->pendulumCards[index] = card;
	return true;
}

void Deck::clearDeck()
{
	this->monsterCards.clear();
	this->magicCards.clear();
	this->pendulumCards.clear();
}

std::string Deck::printDeck() const
{
	std::string result;

	result.append(this->printMonsterCards());
	result.append(this->printMagicCards());
	result.append(this->printPendulumCards());

	return result;
}

std::string Deck::printMonsterCards() const
{
	std::string result;
	for (int i = 0; i < this->getMonsterCardsCount(); i++)
	{
		result.append(this->monsterCards[i].printMonsterCard());
		result.append("\n");
	}
	return result;
}

std::string Deck::printMagicCards() const
{
	std::string result;
	for (int i = 0; i < this->getMagicCardsCount(); i++)
	{
		result.append(this->magicCards[i].printMagicCard());
		result.append("\n");
	}
	return result;
}

std::string Deck::printPendulumCards() const
{
	std::string result;
	for (int i = 0; i < this->getPendulumCardsCount(); i++)
	{
		result.append(this->pendulumCards[i].printPendulumCard());
		result.append("\n");
	}
	return result;
}

std::string Deck::getName() const
{
	return this->name;
}

int Deck::getMonsterCardsCount() const
{
	return this->monsterCards.size();
}

int Deck::getMagicCardsCount() const
{
	return this->magicCards.size();
}

int Deck::getPendulumCardsCount() const
{
	return this->pendulumCards.size();
}
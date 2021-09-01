#include "Deck.hpp"

const std::string invalidIndexError = "Invalid index given.";

Deck::Deck(const std::string name)
	:name(name)
{ }

Deck::Deck(const Deck& rhs)
{
	this->copy(rhs);
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs)
	{
		this->clear();
		this->copy(rhs);
	}
	return *this;
}

Deck::~Deck()
{
	this->clear();
}

void Deck::setName(const std::string& name)
{
	this->name = name;
}

void Deck::addCard(const Card* card)
{
	this->cards.push_back(card->getCopy());
}

bool Deck::changeCard(const int index, const Card* card)
{
	if (index < 0 || index >= this->getCardsCount())
	{
		std::cout << invalidIndexError << std::endl;
		return false;
	}

	if (dynamic_cast<MonsterCard*>(this->cards[index]) && dynamic_cast<const MonsterCard*>(card) && !dynamic_cast<PendulumCard*>(this->cards[index]) && !dynamic_cast<const PendulumCard*>(card) 
		||
		dynamic_cast<MagicCard*>(this->cards[index]) && dynamic_cast<const MagicCard*>(card) && !dynamic_cast<PendulumCard*>(this->cards[index]) && !dynamic_cast<const PendulumCard*>(card)
		||
		dynamic_cast<PendulumCard*>(this->cards[index]) && dynamic_cast<const PendulumCard*>(card))
	{
		delete this->cards[index];
		this->cards[index] = card->getCopy();
		return true;
	}
	return false;
}

void Deck::shuffle()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->cards.begin(), this->cards.end(), std::default_random_engine(seed));
}

void Deck::clear()
{
	for (auto card : this->cards)
	{
		delete card;
	}
	this->cards.clear();
}

std::string Deck::printFullDeck() const
{
	std::string result;

	result.append(this->getName());
	result.append("|");
	result.append(std::to_string(this->getCardsCount()));
	result.append("|");
	result.append(std::to_string(this->getMonsterCardsCount()));
	result.append("|");
	result.append(std::to_string(this->getMagicCardsCount()));
	result.append("|");
	result.append(std::to_string(this->getPendulumCardsCount()));
	result.append("\n");

	result.append(this->printMonsterCards());
	result.append(this->printMagicCards());
	result.append(this->printPendulumCards());

	return result;
}

std::string Deck::printMonsterCards() const
{
	std::string result;
	for (auto card : this->cards)
	{
		if (dynamic_cast<MonsterCard*>(card) && !dynamic_cast<PendulumCard*>(card))
		{
			result.append(card->printCard());
			result.append("\n");
		}
	}
	return result;
}

std::string Deck::printMagicCards() const
{
	std::string result;
	for (auto card : this->cards)
	{
		if (dynamic_cast<MagicCard*>(card) && !dynamic_cast<PendulumCard*>(card))
		{
			result.append(card->printCard());
			result.append("\n");
		}
	}
	return result;
}

std::string Deck::printPendulumCards() const
{
	std::string result;
	for (auto card : this->cards)
	{
		if (dynamic_cast<PendulumCard*>(card))
		{
			result.append(card->printCard());
			result.append("\n");
		}
	}
	return result;
}

std::string Deck::getName() const
{
	return this->name;
}

unsigned Deck::getCardsCount() const
{
	return this->cards.size();
}

unsigned Deck::getMonsterCardsCount() const
{
	unsigned monsterCardsCount = 0;
	for (auto card : this->cards)
	{
		if (dynamic_cast<MonsterCard*>(card) && !dynamic_cast<PendulumCard*>(card))
		{
			monsterCardsCount++;
		}
	}
	return monsterCardsCount;
}

unsigned Deck::getMagicCardsCount() const
{
	unsigned magicCardsCount = 0;
	for (auto card : this->cards)
	{
		if (dynamic_cast<MagicCard*>(card) && !dynamic_cast<PendulumCard*>(card))
		{
			magicCardsCount++;
		}
	}
	return magicCardsCount;
}

unsigned Deck::getPendulumCardsCount() const
{
	unsigned pendulumCardsCount = 0;
	for (auto card : this->cards)
	{
		if (dynamic_cast<PendulumCard*>(card))
		{
			pendulumCardsCount++;
		}
	}
	return pendulumCardsCount;
}

std::pair<unsigned, unsigned> Deck::compareDecks(const Deck& opponentDeck) const
{
	unsigned firstDuelistPoints = 0;
	unsigned secondDuelistPoints = 0;

	for (auto i = 0; i < this->getCardsCount(); i++)
	{
		if (*this->cards[i] > *opponentDeck.cards[i])
		{
			firstDuelistPoints++;
		}
		else if (*this->cards[i] < *opponentDeck.cards[i])
		{
			secondDuelistPoints++;
		}
	}
	return std::pair<unsigned, unsigned>(firstDuelistPoints, secondDuelistPoints);
}

void Deck::copy(const Deck& rhs)
{
	for (auto card : rhs.cards)
	{
		this->addCard(card);
	}
}
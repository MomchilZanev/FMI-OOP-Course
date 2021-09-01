#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "PendulumCard.hpp"

class Deck
{
public:
	Deck() = default;
	Deck(const std::string name);
	Deck(const Deck& rhs);
	Deck& operator=(const Deck& rhs);
	~Deck();

	void setName(const std::string& name);
	void addCard(const Card* card);
	bool changeCard(const int index, const Card* card);
	void shuffle();
	void clear();

	std::string printFullDeck() const;
	std::string printMonsterCards() const;
	std::string printMagicCards() const;
	std::string printPendulumCards() const;

	std::string getName() const;
	unsigned getCardsCount() const;
	unsigned getMonsterCardsCount() const;
	unsigned getMagicCardsCount() const;
	unsigned getPendulumCardsCount() const;	

	std::pair<unsigned, unsigned> compareDecks(const Deck& opponentDeck) const;
private:
	void copy(const Deck& rhs);

	std::string name;
	std::vector<Card*> cards;
};
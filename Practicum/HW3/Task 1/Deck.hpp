#pragma once
#include <iostream>
#include <vector>
#include "PendulumCard.hpp"

class Deck
{
public:
	Deck() = default;
	Deck(const std::string name);
	
	void changeName(const std::string& name);
	void addMonsterCard(const MonsterCard& card);
	void addMagicCard(const MagicCard& card);
	void addPendulumCard(const PendulumCard& card);
	bool changeMonsterCard(const int index, const MonsterCard& card);
	bool changeMagicCard(const int index, const MagicCard& card);
	bool changePendulumCard(const int index, const PendulumCard& card);
	void clearDeck();

	std::string printDeck() const;
	std::string printMonsterCards() const;
	std::string printMagicCards() const;
	std::string printPendulumCards() const;
	std::string getName() const;
	int getMonsterCardsCount() const;
	int getMagicCardsCount() const;
	int getPendulumCardsCount() const;	
private:
	std::string name;
	std::vector<MonsterCard> monsterCards;
	std::vector<MagicCard> magicCards;
	std::vector<PendulumCard> pendulumCards;
};
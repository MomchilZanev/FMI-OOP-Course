#pragma once
#include "Deck.hpp"

class Duelist
{
public:
	Duelist();
	Duelist(const char* name);
	~Duelist();

	int getMonsterCardCountInDeck();
	int getMagicCardCountInDeck();
	void addMonsterCardToDeck(const MonsterCard& card);
	void addMagicCardToDeck(const MagicCard& card);
	void changeMonsterCardInDeck(const int index, const MonsterCard& card);
	void changeMagicCardInDeck(const int index, const MagicCard& card);

	const char* getName() const;
	void setName(const char* name);
private:
	char* name;
	Deck deck;	
};
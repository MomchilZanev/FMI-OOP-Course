#pragma once
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class Deck
{
public:
	static const int MONSTER_CARDS = 20;
	static const int MAGIC_CARDS = 20;

	int getMonsterCardCount();
	int getMagicCardCount();
	void addMonsterCard(const MonsterCard& card);
	void addMagicCard(const MagicCard& card);
	void changeMonsterCard(const int index, const MonsterCard& card);
	void changeMagicCard(const int index, const MagicCard& card);
private:
	MonsterCard monsterCards[MONSTER_CARDS];
	MagicCard magicCards[MAGIC_CARDS];

	int monsterCardIndex = 0;
	int magicCardIndex = 0;
};
#include <iostream>
#include "Deck.hpp"
using namespace std;

void Deck::changeMonsterCard(const int index, const MonsterCard& card)
{
	if (index < 0 || index >= MONSTER_CARDS)
	{
		cout << "Invalid index given" << endl;
		return;
	}

	this->monsterCards[index] = card;
}

void Deck::changeMagicCard(const int index, const MagicCard& card)
{
	if (index < 0 || index >= MAGIC_CARDS)
	{
		cout << "Invalid index given" << endl;
		return;
	}

	this->magicCards[index] = card;
}

void Deck::addMonsterCard(const MonsterCard& card)
{
	while (monsterCardIndex < MONSTER_CARDS && this->monsterCards[monsterCardIndex].isInitialized())
	{
		monsterCardIndex++;
	}

	if (monsterCardIndex >= MONSTER_CARDS)
	{
		cout << "Monster cards deck is full" << endl;
		monsterCardIndex = MONSTER_CARDS - 1;
		return;
	}
	
	this->monsterCards[monsterCardIndex] = card;
}

void Deck::addMagicCard(const MagicCard& card)
{
	while (magicCardIndex < MAGIC_CARDS && this->magicCards[magicCardIndex].isInitialized())
	{
		magicCardIndex++;
	}

	if (magicCardIndex >= MAGIC_CARDS)
	{
		cout << "Magic cards deck is full" << endl;
		magicCardIndex = MAGIC_CARDS - 1;
		return;
	}
	
	this->magicCards[magicCardIndex] = card;
}

int Deck::getMonsterCardCount()
{
	int count = 0;
	for (int i = 0; i < Deck::MONSTER_CARDS; i++)
	{
		if (this->monsterCards[i].isInitialized())
		{
			count++;
		}
	}

	return count;
}

int Deck::getMagicCardCount()
{
	int count = 0;
	for (int i = 0; i < Deck::MAGIC_CARDS; i++)
	{
		if (this->magicCards[i].isInitialized())
		{
			count++;
		}
	}

	return count;
}
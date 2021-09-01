#include <iostream>
#include <cstring>
#include "Duelist.hpp"
using namespace std;


Duelist::Duelist() : name(new char[1])
{
    strcpy_s(this->name, 1, "");
}

Duelist::Duelist(const char* name)
{
    int length = strlen(name);
    length++;
    this->name = new char[length];
    strcpy_s(this->name, length, name);
}

Duelist::~Duelist()
{
    delete[] this->name;
}

int Duelist::getMonsterCardCountInDeck()
{
    return this->deck.getMonsterCardCount();
}

int Duelist::getMagicCardCountInDeck() 
{
    return this->deck.getMagicCardCount();
}

void Duelist::addMonsterCardToDeck(const MonsterCard& card)
{
    this->deck.addMonsterCard(card);
}

void Duelist::addMagicCardToDeck(const MagicCard& card)
{
    this->deck.addMagicCard(card);
}

void Duelist::changeMonsterCardInDeck(const int index, const MonsterCard& card)
{
    this->deck.changeMonsterCard(index, card);
}

void Duelist::changeMagicCardInDeck(const int index, const MagicCard& card)
{
    this->deck.changeMagicCard(index, card);
}

void Duelist::setName(const char* name)
{
    delete[] this->name;
    int length = strlen(name);
    length++;
    this->name = new char[length];
    strcpy_s(this->name, length, name);
}

const char* Duelist::getName() const
{
	return this->name;
}
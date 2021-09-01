#include <iostream>
#include <cstring>
#include "MagicCard.hpp"
using namespace std;

MagicCard::MagicCard()
{
	setName("");
	setEffect("");
}

MagicCard::MagicCard(const char name[NAME_MAX_SIZE], const char effect[EFFECT_NAME_MAX_SIZE], const Type type)
{
	setName(name);
	setEffect(effect);
	setType(type);
	this->initialized = true;
}

void MagicCard::setName(const char name[NAME_MAX_SIZE])
{
	strcpy_s(this->name, NAME_MAX_SIZE, name);
}

void MagicCard::setEffect(const char effect[EFFECT_NAME_MAX_SIZE])
{
	strcpy_s(this->effect, EFFECT_NAME_MAX_SIZE, effect);
}

void MagicCard::setType(const Type type)
{
	this->type = type;
}

const char* MagicCard::getName() const
{
	return this->name;
}

const char* MagicCard::getEffect() const
{
	return this->effect;
}

const Type MagicCard::getType() const
{
	return this->type;
}

bool MagicCard::isInitialized() const
{
	return this->initialized;
}
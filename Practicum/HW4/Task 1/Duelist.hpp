#pragma once
#include <fstream>
#include <sstream>
#include "Deck.hpp"

class Duelist
{
public:
	Duelist() = default;
	Duelist(const std::string& name);

	bool saveDeck(const std::string& fileName) const;
	bool loadDeck(const std::string& fileName);
	Deck& getDeck();
	void duel(Duelist& opponent);

	void changeName(const std::string& name);
	std::string getName() const;	
private:
	void fillContainer(std::ifstream& file, std::vector<std::string>& container) const;
	void loadInformation(std::vector<std::string>& container);
	MonsterCard readMonsterCard(const std::vector<std::string>& container, unsigned& index);
	MagicCard readMagicCard(const std::vector<std::string>& container, unsigned& index);
	PendulumCard readPendulumCard(const std::vector<std::string>& container, unsigned& index);
	void getBaseInfo(const std::vector<std::string>& container, unsigned& index, std::string& name, std::string& effect, unsigned& rarity);
	void getAttackAndDefensePoints(const std::vector<std::string>& container, unsigned& index, unsigned& attackPoints, unsigned& defensePoints);
	CardType getCardType(const std::string& line) const;

	std::string name;
	Deck deck;	
};
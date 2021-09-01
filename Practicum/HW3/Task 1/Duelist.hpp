#pragma once
#include <fstream>
#include <sstream>
#include "Deck.hpp"

class Duelist
{
public:
	Duelist() = default;
	Duelist(const std::string& name);
	Duelist(const std::string& name, const Deck& deck);

	bool saveDeck(const std::string& fileName) const;
	bool loadDeck(const std::string& fileName);
	Deck& getDeck();
	void setDeck(const Deck& deck);
	void changeName(const std::string& name);	

	void display() const;	
	std::string getName() const;	
private:
	std::string printDuelist() const;
	void fillContainer(std::ifstream& file, std::vector<std::string>& container) const;
	void loadInformation(std::vector<std::string>& container);
	CardType getCardType(const std::string& line) const;

	std::string name;
	Deck deck;	
};
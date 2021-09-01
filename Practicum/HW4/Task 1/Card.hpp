#pragma once
#include <string>
#include "Helpers.hpp"

class Card
{
public:
	Card() = default;
	Card(const std::string& name, const std::string& effect, const int rarity);
	virtual ~Card() = default;

	bool operator<(const Card& rhs);
	bool operator>(const Card& rhs);
	
	void changeName(const std::string& name);
	void changeEffect(const std::string& effect);
	void changeRarity(const int rarity);

	virtual std::string printCard() const = 0;	
	std::string getName() const;
	std::string getEffect() const;
	unsigned getRarity() const;

	virtual Card* getCopy() const = 0;
protected:	
	std::string printBaseInfo() const;
private:
	std::string name;
	std::string effect;
	unsigned rarity;
};
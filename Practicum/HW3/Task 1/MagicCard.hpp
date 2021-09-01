#pragma once
#include "Card.hpp"

enum class CardType
{
	TRAP,
	BUFF, 
	SPELL
};

class MagicCard : virtual public Card
{
public:
	MagicCard() = default;
	MagicCard(const std::string& name, const std::string& effect, const CardType type);

	void changeType(const CardType type);

	std::string printMagicCard() const;
	const CardType getType() const;
protected:
	std::string printType() const;
private:
	CardType type;
};
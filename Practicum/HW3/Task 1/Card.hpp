#pragma once
#include <string>

class Card
{
public:
	Card() = default;
	Card(const std::string& name, const std::string& effect);
	
	void changeName(const std::string& name);
	void changeEffect(const std::string& effect);

	std::string printCard() const;
	std::string getName() const;
	std::string getEffect() const;
private:
	std::string name;
	std::string effect;
};
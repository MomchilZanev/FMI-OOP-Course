#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include "EffectsMethods.hpp"
#include "Helpers.hpp"

enum class ArmorType
{
	cloth, 
	leather, 
	mail
};

class Armor
{
public:
	Armor();
	Armor(const ArmorType& type, const int defense);

	Armor& operator=(const Armor& rhs);
	bool operator==(const Armor& rhs) const;

	void print() const;
	void addEffect(const std::string& name, const double& power);		 
	void removeEffect(const std::string& name);							 
	void changeEffectPower(const std::string& name, const double& power);
	void changeDefense(const int defense);

	unsigned int getSlotsNeeded() const;
	double getScore() const;
	ArmorType getType() const;
	unsigned int getDefense() const;
	const unsigned int SLOTS_OCCUPIED = 1;
	const unsigned int DEFAULT_DEFENSE = 10;
	const ArmorType DEFAULT_ARMOR_TYPE = ArmorType::cloth;
private:
	ArmorType type;
	unsigned int defense; 
	std::vector<std::pair<std::string, double>> effects;
};
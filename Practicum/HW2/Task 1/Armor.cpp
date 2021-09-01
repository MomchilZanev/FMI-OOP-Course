#include "Armor.hpp"

Armor::Armor() 
	: type(this->DEFAULT_ARMOR_TYPE), defense(this->DEFAULT_DEFENSE)
{ }

Armor::Armor(const ArmorType& type, const int defense)
{
	this->type = type;
	this->defense = getAbs<int>(defense);
}

Armor& Armor::operator=(const Armor& rhs)
{
	if (&rhs != this)
	{
		this->type = rhs.getType();
		this->defense = rhs.getDefense();
		this->effects = rhs.effects;
	}
	return *this;
}

bool Armor::operator==(const Armor& rhs) const
{
	return 
		this->getType() == rhs.getType() 
		&& this->getDefense() == rhs.getDefense() 
		&& this->getScore() == rhs.getScore();
}

void Armor::print() const
{
	std::map<ArmorType, std::string> armorTypeMap;
	armorTypeMap[ArmorType::cloth] = "Cloth";
	armorTypeMap[ArmorType::leather] = "Leather";
	armorTypeMap[ArmorType::mail] = "Mail";

	std::cout << std::fixed << std::setprecision(2)
		<< "\nArmor Type: " << armorTypeMap[this->getType()] 
		<< "\nDefense: " << this->getDefense()
		<< "\nSlots Needed: " << this->getSlotsNeeded()
		<< "\nGear Score: " << this->getScore()
		<< std::endl;

	EffectsMethods::printAllEffects(this->effects);
}
void Armor::addEffect(const std::string& name, const double& power)
{
	EffectsMethods::addEffect(this->effects, name, power);
}

void Armor::removeEffect(const std::string& name)
{
	EffectsMethods::removeEffect(this->effects, name);
}

void Armor::changeEffectPower(const std::string& name, const double& power)
{
	EffectsMethods::addEffect(this->effects, name, power);
}

void Armor::changeDefense(const int defense)
{
	this->defense = getAbs<int>(defense);
}

unsigned int Armor::getSlotsNeeded() const
{
	return this->SLOTS_OCCUPIED;
}

double Armor::getScore() const
{
	double totalGearScore = 0;
	for (int i = 0; i < this->effects.size(); i++)
	{
		totalGearScore += this->effects[i].second;
	}

	return totalGearScore;
}

ArmorType Armor::getType() const
{
	return this->type;
}

unsigned int Armor::getDefense() const
{
	return this->defense;
}
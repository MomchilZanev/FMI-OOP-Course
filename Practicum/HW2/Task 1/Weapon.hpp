#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include "EffectsMethods.hpp"
#include "Helpers.hpp"

enum class WeaponType
{
	oneHanded = 1, 
	twoHanded //2
};

enum class WeaponCategory
{
	sword,
	axe, 
	mace,
	dagger,	
	staff
};

class Weapon
{
public:
	Weapon();
	Weapon(const WeaponType& type, const WeaponCategory& category, const double& hitDamageLow, const double& hitDamageHigh);

	Weapon& operator=(const Weapon& rhs);
	bool operator==(const Weapon& rhs) const;

	void print() const;
	void addEffect(const std::string& name, const double& power);		  
	void removeEffect(const std::string& name);							  
	void changeEffectPower(const std::string& name, const double& power); 
	void changeHitDamage(const double& hitDamageLow, const double& hitDamageHigh);
	void changeWeaponType(const WeaponType& type);
	void changeWeaponCategory(const WeaponCategory& category);

	unsigned int getSlotsNeeded() const;
	WeaponType getType() const;
	WeaponCategory getCategory() const;
	double getHitDamageLow() const;
	double getHitDamageHigh() const;
	double getAverageDamage() const;
	double getScore() const;

	const WeaponType DEFAULT_WEAPON_TYPE = WeaponType::oneHanded;
	const WeaponCategory DEFAULT_WEAPON_CATEGORY = WeaponCategory::sword;
	const double DEFAULT_WEAPON_DAMAGE_HIGH = 75.0;
	const double DEFAULT_WEAPON_DAMAGE_LOW = 25.0;
private:
	bool checkWeaponCategoryTypeCompatibility(const WeaponType& type, const WeaponCategory& category) const;

	WeaponType type;
	WeaponCategory category;
	std::pair<double, double> hitDamage; 
	std::vector<std::pair<std::string, double>> effects;
};
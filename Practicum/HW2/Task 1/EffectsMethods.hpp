#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Helpers.hpp"

class EffectsMethods
{
private:
	static bool effectExists(const std::vector<std::pair<std::string, double>>& container, const std::string& name);					
	static void addEffect(std::vector<std::pair<std::string, double>>& container, const std::string& name, const double& power);		
	static void removeEffect(std::vector<std::pair<std::string, double>>& container, const std::string& name);							
	static void changeEffectPower(std::vector<std::pair<std::string, double>>& container, const std::string& name, const double& power);
	static void printAllEffects(const std::vector<std::pair<std::string, double>>& container);											

	friend class Armor;
	friend class Weapon;
};
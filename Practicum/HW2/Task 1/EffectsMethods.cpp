#include "EffectsMethods.hpp"

bool EffectsMethods::effectExists(const std::vector<std::pair<std::string, double>>& container, const std::string& name)
{
	for (int i = 0; i < container.size(); i++)
	{
		if (container[i].first == name)
		{
			return true;
		}
	}
	return false;
}

void EffectsMethods::addEffect(std::vector<std::pair<std::string, double>>& container, const std::string& name, const double& power)
{
	if (effectExists(container, name))
	{
		changeEffectPower(container, name, power);
		return;
	}

	container.push_back(std::pair<std::string, double>(name, getAbs<double>(power)));
}

void EffectsMethods::removeEffect(std::vector<std::pair<std::string, double>>& container, const std::string& name)
{
	if (!effectExists(container, name))
	{
		return;
	}

	for (int i = 0; i < container.size(); i++)
	{
		if (container[i].first == name)
		{
			container.erase(container.begin() + i);
			return;
		}
	}
}

void EffectsMethods::changeEffectPower(std::vector<std::pair<std::string, double>>& container, const std::string& name, const double& power)
{
	if (!effectExists(container, name))
	{
		return;
	}

	for (int i = 0; i < container.size(); i++)
	{
		if (container[i].first == name)
		{
			container[i].second = getAbs<double>(power);
			return;
		}
	}
}

void EffectsMethods::printAllEffects(const std::vector<std::pair<std::string, double>>& container)
{
	std::cout << "Effects: " << std::endl;
	for (int i = 0; i < container.size(); i++)
	{
		std::cout << '\t' << container[i].first << " - " << container[i].second << std::endl;
	}
}
#pragma once

class MonsterCard
{
public:
	static const int NAME_MAX_SIZE = 26;

	MonsterCard();
	MonsterCard(const char name[NAME_MAX_SIZE], const unsigned int attackPoints, const unsigned int defensePoints);

	const char* getName() const;
	unsigned int getAttackPoints() const;
	unsigned int getDefensePoints() const;
	bool isInitialized() const;

	void setName(const char name[NAME_MAX_SIZE]);
	void setAttackPoints(const unsigned int attackPoints);
	void setDefensePoints(const unsigned int defensePoints);
private:	
	char name[NAME_MAX_SIZE];
	unsigned int attackPoints;
	unsigned int defensePoints;

	bool initialized = false;
};
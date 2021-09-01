#pragma once

enum Type
{
	trap,
	buff, 
	spell
};

class MagicCard
{
public:
	static const int NAME_MAX_SIZE = 26;
	static const int EFFECT_NAME_MAX_SIZE = 101;

	MagicCard();
	MagicCard(const char name[NAME_MAX_SIZE], const char effect[EFFECT_NAME_MAX_SIZE], const Type type);

	const char* getName() const;
	const char* getEffect() const;
	const Type getType() const;
	bool isInitialized() const;

	void setName(const char name[NAME_MAX_SIZE]);
	void setEffect(const char effect[EFFECT_NAME_MAX_SIZE]);
	void setType(const Type type);
private:	
	char name[NAME_MAX_SIZE];
	char effect[EFFECT_NAME_MAX_SIZE];
	Type type;

	bool initialized = false;
};
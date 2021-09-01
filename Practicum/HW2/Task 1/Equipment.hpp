#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Equipment
{
public:
	Equipment<T>& operator=(const Equipment<T>& rhs);
	bool operator==(const Equipment<T>& rhs) const;
	bool operator!=(const Equipment<T>& rhs) const;

	void print() const;
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	void add(const T& content);
	void remove(const T& content);
	const T& getBestEquipment() const;
	unsigned int getSlotsOccupied() const;
	double getTotalEquipmentScore() const;
private:
	std::vector<T> contents;
	const unsigned int slots = 24;
};

template<typename T>
Equipment<T>& Equipment<T>::operator=(const Equipment<T>& rhs)
{
	if (&rhs != this)
	{
		this->contents = rhs.contents;
	}
	return *this;	
}

template<typename T>
bool Equipment<T>::operator==(const Equipment<T>& rhs) const
{
	return this->getTotalEquipmentScore() == rhs.getTotalEquipmentScore();
}

template<typename T>
bool Equipment<T>::operator!=(const Equipment<T>& rhs) const
{
	return !(*this == rhs);
}

template<typename T>
void Equipment<T>::print() const
{
	std::cout << "\nFull Equipment: ";
	for (unsigned int i = 0; i < contents.size(); i++)
	{
		contents[i].print();
	}
	std::cout 
		<< "\nTotal Equipment Score: " << this->getTotalEquipmentScore()
		<< "\nSlots Occupied: " << this->getSlotsOccupied() << std::endl;
}

template<typename T>
bool Equipment<T>::isEmpty() const
{
	return this->contents.size() == 0;
}

template<typename T>
bool Equipment<T>::isFull() const
{
	return this->getSlotsOccupied() == this->slots;
}

template<typename T>
void Equipment<T>::clear()
{
	this->contents.clear();
}

template<typename T>
void Equipment<T>::add(const T& content)
{
	if (this->getSlotsOccupied() + content.getSlotsNeeded() <= this->slots)
	{
		this->contents.push_back(content);
	}
}

template<typename T>
void Equipment<T>::remove(const T& content)
{
	if (this->isEmpty())
	{
		return;
	}

	for (unsigned int i = 0; i < this->contents.size(); i++)
	{
		if (this->contents[i] == content)
		{
			this->contents.erase(this->contents.begin() + i);
			return;
		}
	}
}

template<typename T>
const T& Equipment<T>::getBestEquipment() const
{
	if (this->isEmpty())
	{
		return T();
	}

	double bestScore = -1;
	int bestIndex = 0;
	for (unsigned int i = 0; i < this->contents.size(); i++)
	{
		if (this->contents[i].getScore() > bestScore)
		{
			bestScore = this->contents[i].getScore();
			bestIndex = i;
		}
	}

	return this->contents[bestIndex];
}

template<typename T>
double Equipment<T>::getTotalEquipmentScore() const
{
	double totalScore = 0;
	for (unsigned int i = 0; i < this->contents.size(); i++)
	{
		totalScore += this->contents[i].getScore();
	}
	return totalScore;
}

template<typename T>
unsigned int Equipment<T>::getSlotsOccupied() const
{
	unsigned int result = 0;
	for (unsigned int i = 0; i < contents.size(); i++)
	{
		result += contents[i].getSlotsNeeded();
	}
	return result;
}
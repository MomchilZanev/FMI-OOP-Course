#pragma once
#include <iostream>

template <typename T, typename W>
class Inventory
{
public:
	Inventory(const T& invetoryType);
	bool operator==(const Inventory<T, W>& rhs) const;
	bool operator!=(const Inventory<T, W>& rhs) const;

	bool isEmpty() const;
	bool isFull() const;
	void clear();
	void add(const W& content);
	void remove(const W& content);

	friend std::ostream& operator<<(std::ostream& output, const Inventory<T, W>& rhs)
	{
		//Hacky but I did the task bottom up and I'm not reworking all my print methods
		rhs.invetoryType.print();
		return output << "";
	}
private:
	T invetoryType;
};

template <typename T, typename W>
Inventory<T, W>::Inventory(const T& invetoryType)
{
	this->invetoryType = invetoryType;
}

template <typename T, typename W>
bool Inventory<T, W>::operator==(const Inventory<T, W>& rhs) const
{
	return this->invetoryType.getSlotsOccupied() == rhs.invetoryType.getSlotsOccupied();
}

template <typename T, typename W>
bool Inventory<T, W>::operator!=(const Inventory<T, W>& rhs) const
{
	return !(*this == rhs);
}

template<typename T, typename W>
bool Inventory<T, W>::isEmpty() const
{
	return this->invetoryType.isEmpty();
}

template<typename T, typename W>
bool Inventory<T, W>::isFull() const
{
	return this->invetoryType.isFull();
}

template<typename T, typename W>
void Inventory<T, W>::clear()
{
	this->invetoryType.clear();
}

template<typename T, typename W>
void Inventory<T, W>::add(const W& content)
{
	this->invetoryType.add(content);
}

template<typename T, typename W>
void Inventory<T, W>::remove(const W& content)
{
	this->invetoryType.remove(content);
}
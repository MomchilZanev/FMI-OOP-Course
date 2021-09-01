#pragma once

template <typename T>
class Backpack
{
public:
	Backpack();
	Backpack(const T& contents);

	Backpack<T>& operator=(const Backpack<T>& rhs);

	void print() const;
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	void add(const T& content);
	void remove(const T& content);
	unsigned int getSlotsOccupied() const;
private:
	T contents;
	unsigned int slots;
};

template<typename T>
Backpack<T>::Backpack() : contents(T())
{
	this->slots = this->contents.MAX_SLOTS;
}

template<typename T>
Backpack<T>::Backpack(const T& contents) : slots(contents.MAX_SLOTS), contents(contents)
{ }

template<typename T>
Backpack<T>& Backpack<T>::operator=(const Backpack<T> & rhs)
{
	if (&rhs != this)
	{
		this->contents = rhs.contents;
		this->slots = rhs.slots;
	}
	return *this;
}

template<typename T>
void Backpack<T>::print() const
{
	this->contents.print();
}

template<typename T>
bool Backpack<T>::isEmpty() const
{
	return this->contents.isEmpty();
}

template<typename T>
bool Backpack<T>::isFull() const
{
	return this->contents.isFull();
}

template<typename T>
void Backpack<T>::clear()
{
	this->contents.clearAll();
}

template<typename T>
void Backpack<T>::add(const T& content)
{
	this->contents.add(content);
}

template<typename T>
void Backpack<T>::remove(const T& content)
{
	this->contents.remove(content);
}

template<typename T>
unsigned int Backpack<T>::getSlotsOccupied() const
{
	return this->contents.slotsOccupied();
}
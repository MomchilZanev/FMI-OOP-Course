#include "drink.hpp"

Drink::Drink() : calories(0), quantity(0), price(0)
{
	this->copyName("");
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) : calories(init_calories), quantity(init_quantity), price(init_price)
{
	this->copyName(init_name);
}

Drink::Drink(const Drink& rhs) : calories(rhs.get_calories()), quantity(rhs.get_quantity()), price(rhs.get_price())
{
	this->copyName(rhs.get_name());
}

Drink& Drink::operator=(const Drink& rhs)
{
	if (this != &rhs)
	{
		this->set_name(rhs.get_name());
		this->calories = rhs.get_calories();
		this->quantity = rhs.get_quantity();
		this->price = rhs.get_price();
	}
	return *this;
}

Drink::~Drink()
{
	delete[] this->name;
}

const char* Drink::get_name() const
{
	return this->name;
}

int Drink::get_calories() const
{
	return this->calories;
}

double Drink::get_quantity() const
{
	return this->quantity;
}

double Drink::get_price() const
{
	return this->price;
}

void Drink::set_name(const char* new_name)
{
	delete[] this->name;
	copyName(new_name);
}

void Drink::copyName(const char* new_name)
{
	if (new_name == nullptr)
	{
		this->name = nullptr;
	}
	const int length = strlen(new_name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, new_name);
}
#include "VendingMachine.hpp"

VendingMachine::VendingMachine() : money(0), drinksInside(0)
{
	this->drinks = nullptr;
}

VendingMachine::VendingMachine(const VendingMachine& from) : money(from.get_income()), drinksInside(from.get_drinksCount())
{
	this->drinks = new Drink[from.get_drinksCount()];
	copyDrinks(this->drinks, from.drinks, from.get_drinksCount());
}

VendingMachine::~VendingMachine()
{
	delete[] this->drinks;
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (this != &from)
	{
		this->money = from.get_income();
		this->drinksInside = from.get_drinksCount();
		delete[] this->drinks;
		this->drinks = new Drink[from.get_drinksCount()];
		copyDrinks(this->drinks, from.drinks, from.get_drinksCount());
	}

	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	for (int i = 0; i < this->get_drinksCount(); i++)
	{
		if (namesAreEqual(this->drinks[i].get_name(), to_add.get_name()))
		{
			return false;
		}
	}

	Drink* newContainer = new Drink[this->get_drinksCount() + 1];
	copyDrinks(newContainer, this->drinks, this->get_drinksCount());
	newContainer[this->get_drinksCount()] = to_add;
	delete[] this->drinks;
	this->drinks = newContainer;
	drinksInside++;

	return true;;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	for (int i = 0; i < this->get_drinksCount(); i++)
	{
		if (namesAreEqual(this->drinks[i].get_name(), drink_name))
		{
			if (this->drinks[i].get_price() > money)
			{
				this->money += money;

				return 1;
			}

			if (this->get_drinksCount() == 1)
			{
				delete[] this->drinks;
				this->drinks = nullptr;
			}
			else
			{
				Drink* newContainer = new Drink[this->get_drinksCount() -1];
				copyDrinks(newContainer, this->drinks, this->get_drinksCount(), i);
				delete[] this->drinks;
				this->drinks = newContainer;
			}			
			drinksInside--;
			this->money += money;

			return 0;
		}
	}

	return 2;
}

double VendingMachine::get_income() const
{
	return this->money;
}

int VendingMachine::get_drinksCount() const
{
	return this->drinksInside;
}

void VendingMachine::copyDrinks(Drink* destination, const Drink* source, const int sourceSize, const int excludeIndex)
{
	for (int sourceIndex = 0, destinationIndex = 0; sourceIndex < sourceSize;)
	{
		if (sourceIndex != excludeIndex)
		{
			destination[destinationIndex] = source[sourceIndex];
			destinationIndex++;
		}
		sourceIndex++;
	}
}

bool VendingMachine::namesAreEqual(const char* lhs, const char* rhs)
{
	int llen = strlen(lhs);
	int rlen = strlen(rhs);
	if (llen == rlen)
	{
		for (int i = 0; i <= llen; i++)
		{
			if (lhs[i] != rhs[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

void VendingMachine::printStatus()
{
	std::cout << "Available drinks:" << std::endl;
	for (int i = 0; i < this->get_drinksCount(); i++)
	{
		std::cout << '\t' << this->drinks[i].get_name()
			<< " - Quantity: " << this->drinks[i].get_quantity()
			<< ", Calories: " << this->drinks[i].get_calories()
			<< ", Price: " << this->drinks[i].get_price()
			<< std::endl;
	}
	std::cout << "Money inside machine: " << this->get_income() << std::endl;
}
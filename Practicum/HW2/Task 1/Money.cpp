#include "Money.hpp"

Money::Money() : silver(0), gold(0)
{ }

Money::Money(const int silver, const int gold) : silver(getAbs<int>(silver)), gold(getAbs<int>(gold))
{
    this->convertCurrency();
}

Money& Money::operator=(const Money& rhs)
{
    if (&rhs != this)
    {
        this->silver = rhs.getSilver();
        this->gold = rhs.getGold();
    }
    return *this;
}

void Money::print() const
{
    std::cout 
        << "\nThere are " << this->getGold() << " gold coins, and "
        << this->getSilver() << " silver coins in the moneybag."
        << "\nSlots Occupied: " << this->slotsOccupied()
        << std::endl;
}

void Money::clearAll()
{
    this->gold = 0;
    this->silver = 0;
}

void Money::add(const Money& money)
{
    this->gold += money.gold;
    this->silver += money.silver;
    this->convertCurrency();
}

void Money::remove(const Money& money)
{
    const unsigned int currentTotal = this->getSilver() + this->getGold() * 100; //In silver
    const unsigned int removeTotal = money.getSilver() + money.getGold() * 100; //In silver
    
    this->gold = 0;
    this->silver = getMax<int>(currentTotal - removeTotal, 0);    
    this->convertCurrency();
}

bool Money::isEmpty() const
{
    return this->getGold() == 0 && this->getSilver() == 0;
}

bool Money::isFull() const
{
    return false;
}

unsigned int Money::slotsOccupied() const
{
    return this->isEmpty() ? 0 : 1;
}

unsigned int Money::getSilver() const
{
    return this->silver;
}

unsigned int Money::getGold() const
{
    return this->gold;
}

void Money::convertCurrency()
{
    while (this->silver >= 100)
    {
        this->gold++;
        this->silver -= 100;
    }
}
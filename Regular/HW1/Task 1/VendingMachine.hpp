#pragma once
#include "drink.hpp"
#include <iostream>
#include <cstring>

class VendingMachine 
{
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    ~VendingMachine(); 
    VendingMachine& operator=(const VendingMachine& from);
    
    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;
    int get_drinksCount() const;
    void printStatus();
private:
    bool namesAreEqual(const char* lhs, const char* rhs);
    void copyDrinks(Drink* destination, const Drink* source, const int sourceSize, const int excludeIndex = -1);

    double money;
    int drinksInside;    
    Drink* drinks;    
};

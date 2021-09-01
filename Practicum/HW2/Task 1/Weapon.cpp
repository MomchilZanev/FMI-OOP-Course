#include "Weapon.hpp"

Weapon::Weapon() : 
    type(this->DEFAULT_WEAPON_TYPE),
    category(this->DEFAULT_WEAPON_CATEGORY),
    hitDamage(std::pair<double, double>(DEFAULT_WEAPON_DAMAGE_LOW, DEFAULT_WEAPON_DAMAGE_HIGH)),
    effects(std::vector<std::pair<std::string, double>>())
{ }

// If we're given incompatible type and category we create a default sword
Weapon::Weapon(const WeaponType & type, const WeaponCategory & category, const double& hitDamageLow, const double& hitDamageHigh)
    : type(this->DEFAULT_WEAPON_TYPE), category(this->DEFAULT_WEAPON_CATEGORY)
{    
    if (this->checkWeaponCategoryTypeCompatibility(type, category))
    {
        this->type = type;
        this->category = category;
    }
    this->changeHitDamage(hitDamageLow, hitDamageHigh);
}

Weapon& Weapon::operator=(const Weapon& rhs)
{
    if (&rhs != this)
    {
        this->type = rhs.getType();
        this->category = rhs.getCategory();
        this->hitDamage = rhs.hitDamage;
        this->effects = rhs.effects;
    }
    return *this;
}

bool Weapon::operator==(const Weapon& rhs) const
{
    return 
        this->getType() == rhs.getType()
        && this->getCategory() == rhs.getCategory()
        && this->getHitDamageLow() == rhs.getHitDamageLow()
        && this->getHitDamageHigh() == rhs.getHitDamageHigh()
        && this->getScore() == rhs.getScore();
}

void Weapon::print() const
{
    std::map<WeaponType, std::string> weaponTypeMap;
    weaponTypeMap[WeaponType::oneHanded] = "One-Handed";
    weaponTypeMap[WeaponType::twoHanded] = "Two-Handed";

    std::map<WeaponCategory, std::string> weaponCategoryMap;
    weaponCategoryMap[WeaponCategory::axe] = "Axe";
    weaponCategoryMap[WeaponCategory::sword] = "Sword";
    weaponCategoryMap[WeaponCategory::dagger] = "Dagger";
    weaponCategoryMap[WeaponCategory::mace] = "Mace";
    weaponCategoryMap[WeaponCategory::staff] = "Staff";

    std::cout << std::fixed << std::setprecision(2)
        << "\nWeapon Type: " << weaponTypeMap[this->getType()]
        << "\nWeapon Category: " << weaponCategoryMap[this->getCategory()]
        << "\nSlots Needed: " << this->getSlotsNeeded()
        << "\nAverage Hit Damage: " << this->getAverageDamage()
        << "\nWeapon Score: " << this->getScore()
        << std::endl;

    EffectsMethods::printAllEffects(this->effects);
}

void Weapon::addEffect(const std::string& name, const double& power)
{
    EffectsMethods::addEffect(this->effects, name, power);
}

void Weapon::removeEffect(const std::string& name)
{
    EffectsMethods::removeEffect(this->effects, name);
}

void Weapon::changeEffectPower(const std::string& name, const double& power)
{
    EffectsMethods::addEffect(this->effects, name, power);
}

void Weapon::changeHitDamage(const double& hitDamageLow, const double& hitDamageHigh)
{
    // Switch high/low if they're given in wrong order
    if (getAbs<double>(hitDamageLow) > getAbs<double>(hitDamageHigh))
    {
        this->hitDamage.first = hitDamageHigh;
        this->hitDamage.second = hitDamageLow;
        return;
    }

    this->hitDamage.first = getAbs<double>(hitDamageLow);
    this->hitDamage.second = getAbs<double>(hitDamageHigh);
}

// If the type given is not compatible with the current category, we reset the weapon to a default sword
void Weapon::changeWeaponType(const WeaponType& type)
{
    if (!this->checkWeaponCategoryTypeCompatibility(type, this->getCategory()))
    {
        this->category = WeaponCategory::sword;
    }
    this->type = type;
}

// If the category given is not compatible with the current type, we switch the type
void Weapon::changeWeaponCategory(const WeaponCategory& category)
{
    if (!this->checkWeaponCategoryTypeCompatibility(this->getType(), category))
    {
        (int)this->getType() == 1 ? this->type = WeaponType::twoHanded : this->type = WeaponType::oneHanded;
    }
    this->category = category;
}

unsigned int Weapon::getSlotsNeeded() const
{
    return (unsigned int)this->getType();
}

WeaponType Weapon::getType() const
{
    return this->type;
}

WeaponCategory Weapon::getCategory() const
{
    return this->category;
}

double Weapon::getHitDamageLow() const
{
    return this->hitDamage.first;
}

double Weapon::getHitDamageHigh() const
{
    return this->hitDamage.second;
}

double Weapon::getAverageDamage() const
{
    return (this->hitDamage.first + hitDamage.second) / 2;
}

double Weapon::getScore() const
{
    double totalWeaponScore = this->getAverageDamage();
    for (int i = 0; i < this->effects.size(); i++)
    {
        totalWeaponScore += this->effects[i].second;
    }

    if (this->getType() == WeaponType::oneHanded)
    {
        totalWeaponScore *= 0.75;
    }
    else
    {
        totalWeaponScore *= 1.5;
    }

    return totalWeaponScore;
}

bool Weapon::checkWeaponCategoryTypeCompatibility(const WeaponType& type, const WeaponCategory& category) const
{
    switch (category)
    {
    case WeaponCategory::axe : 
        return true;
    case WeaponCategory::dagger :
    {
        if (type == WeaponType::oneHanded)
        {
            return true;
        }
        break;
    }
    case WeaponCategory::mace :
        return true;
    case WeaponCategory::staff :
    {
        if (type == WeaponType::twoHanded)
        {
            return true;
        }
        break;
    }
    case WeaponCategory::sword :
        return true;
    }

    return false;
}
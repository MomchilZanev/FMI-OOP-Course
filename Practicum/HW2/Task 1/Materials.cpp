#include "Materials.hpp"

Materials::Materials() 
    : herbs(0), ores(0), cloth(0), essence(0)
{ }

Materials::Materials(const int herbs, const int ores, const int cloth, const int essence)
    : herbs(getAbs<int>(herbs)), ores(getAbs<int>(ores)),
    cloth(getAbs<int>(cloth)), essence(getAbs<int>(essence))
{
    if (this->slotsOccupied() > this->MAX_SLOTS)
    {
        this->clearAll();
    }    
}

Materials& Materials::operator=(const Materials& rhs)
{
    if (&rhs != this)
    {
        this->herbs = rhs.getHerbs();
        this->ores = rhs.getOres();
        this->cloth = rhs.getCloth();
        this->essence = rhs.getEssence();
    }
    return *this;
}

void Materials::print() const
{
    std::cout
        << "\nThere are " << this->getHerbs() << " herbs, "
        << this->getOres() << " ores, "
        << this->getCloth() << " cloth and "
        << this->getEssence() << " essence in the materials bag."
        << "\nSlots Occupied: " << this->slotsOccupied()
        << std::endl;
}

void Materials::clearAll()
{
    this->herbs = 0;
    this->ores = 0;
    this->cloth = 0;
    this->essence = 0;
}

void Materials::add(const Materials& materials)
{
    this->herbs += materials.getHerbs();
    this->ores += materials.getOres();
    this->cloth += materials.getCloth();
    this->essence += materials.getEssence();

    // If we're asked to add more materials than we can fit, we do not add any
    if (this->slotsOccupied() > this->MAX_SLOTS)
    {
        this->herbs -= materials.getHerbs();
        this->ores -= materials.getOres();
        this->cloth -= materials.getCloth();
        this->essence -= materials.getEssence();
    }
}

void Materials::remove(const Materials& materials)
{
    this->herbs = getMax<int>(this->getHerbs() - materials.getHerbs(), 0);
    this->ores = getMax<int>(this->getOres() - materials.getOres(), 0);
    this->cloth = getMax<int>(this->getCloth() - materials.getCloth(), 0);
    this->essence = getMax<int>(this->getEssence() - materials.getEssence(), 0);
}

bool Materials::isEmpty() const
{
    return this->slotsOccupied() == 0;
}

bool Materials::isFull() const
{
    if (this->slotsOccupied() == this->MAX_SLOTS)
    {
        return this->getHerbs() % this->MAX_OTHER_IN_SLOT == 0
            && this->getOres() % this->MAX_OTHER_IN_SLOT == 0
            && this->getCloth() % this->MAX_OTHER_IN_SLOT == 0
            && this->getEssence() % this->MAX_ESSENCE_IN_SLOT == 0;
    }
    return false;
}

unsigned int Materials::slotsOccupied() const
{
    unsigned int slotsOccupied = 0;
    slotsOccupied += getSlotsOccupiedByItem(this->herbs, this->MAX_OTHER_IN_SLOT);
    slotsOccupied += getSlotsOccupiedByItem(this->ores, this->MAX_OTHER_IN_SLOT);
    slotsOccupied += getSlotsOccupiedByItem(this->cloth, this->MAX_OTHER_IN_SLOT);
    slotsOccupied += getSlotsOccupiedByItem(this->essence, this->MAX_ESSENCE_IN_SLOT);

    return slotsOccupied;
}

unsigned int Materials::getHerbs() const
{
    return this->herbs;
}

unsigned int Materials::getOres() const
{
    return this->ores;
}

unsigned int Materials::getCloth() const
{
    return this->cloth;
}

unsigned int Materials::getEssence() const
{
    return this->essence;
}

unsigned int Materials::getSlotsOccupiedByItem(const unsigned int itemQuantity, const unsigned int maxOfItemInSlot) const
{
    unsigned int slotsOccupied;
    itemQuantity % maxOfItemInSlot != 0 ? slotsOccupied = (itemQuantity / maxOfItemInSlot) + 1 : slotsOccupied = (itemQuantity / maxOfItemInSlot);
    return slotsOccupied;
}
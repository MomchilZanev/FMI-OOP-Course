#include "Duelist.hpp"

Duelist::Duelist(const std::string& name)
    :name(name)
{ }

Duelist::Duelist(const std::string& name, const Deck& deck)
    :name(name), deck(deck)
{ }

bool Duelist::saveDeck(const std::string & fileName) const
{
    std::ofstream file;

    file.open(fileName);
    if (file.is_open())
    {
        file << this->printDuelist();

        file.close();
        return true;
    }
    return false;
}

bool Duelist::loadDeck(const std::string& fileName)
{
    std::ifstream file;

    file.open(fileName);
    if (file.is_open())
    {
        std::vector<std::string> infoContainer;
        this->fillContainer(file, infoContainer);
        this->loadInformation(infoContainer);

        file.close();
        return true;
    }
    return false;
}

void Duelist::changeName(const std::string& name)
{
    this->name = name;
}

Deck& Duelist::getDeck()
{
    return this->deck;
}

void Duelist::setDeck(const Deck& deck)
{
    this->deck = deck;
}

void Duelist::display() const
{
    std::cout << this->printDuelist();
}

std::string Duelist::printDuelist() const
{
    std::string result;

    result.append(this->getName());
    result.append("|");
    result.append(std::to_string(this->deck.getMonsterCardsCount()));
    result.append("|"); 
    result.append(std::to_string(this->deck.getMagicCardsCount()));
    result.append("|"); 
    result.append(std::to_string(this->deck.getPendulumCardsCount()));
    result.append("\n");
    result.append(this->deck.printDeck());

    return result;
}

std::string Duelist::getName() const
{
    return this->name;
}

void Duelist::fillContainer(std::ifstream& file, std::vector<std::string>& container) const
{
    std::string line;
    while (std::getline(file, line, '\n'))
    {
        std::stringstream stream(line);
        std::string current;
        while (std::getline(stream, current, '|'))
        {
            container.push_back(current);
        }
    }
}

void Duelist::loadInformation(std::vector<std::string>& container)
{
    int currentIndex = 0;
    std::string duelistName = container[currentIndex++];
    this->changeName(duelistName);

    this->getDeck().clearDeck();
    int monsterCardsCount = std::stoi(container[currentIndex++]);
    int magicCardsCount = std::stoi(container[currentIndex++]);
    int pendulumCardsCount = std::stoi(container[currentIndex++]);

    for (int i = 0; i < monsterCardsCount; i++)
    {
        std::string name = container[currentIndex++];
        std::string effect = container[currentIndex++];
        unsigned int attackPoints = std::stoi(container[currentIndex++]);
        unsigned int defensePoints = std::stoi(container[currentIndex++]);
        this->getDeck().addMonsterCard(MonsterCard(name, effect, attackPoints, defensePoints));
    }

    for (int i = 0; i < magicCardsCount; i++)
    {
        std::string name = container[currentIndex++];
        std::string effect = container[currentIndex++];
        std::string typeStr = container[currentIndex++];
        this->getDeck().addMagicCard(MagicCard(name, effect, this->getCardType(typeStr)));
    }

    for (int i = 0; i < pendulumCardsCount; i++)
    {
        std::string name = container[currentIndex++];
        std::string effect = container[currentIndex++];
        unsigned int attackPoints = std::stoi(container[currentIndex++]);
        unsigned int defensePoints = std::stoi(container[currentIndex++]);
        unsigned int pendulumScale = std::stoi(container[currentIndex++]);
        std::string typeStr = container[currentIndex++];
        this->getDeck().addPendulumCard(PendulumCard(name, effect, attackPoints, defensePoints, pendulumScale, this->getCardType(typeStr)));
    }
}

CardType Duelist::getCardType(const std::string& line) const
{
    CardType type;

    if (line == "SPELL")
    {
        type = CardType::SPELL;
    }
    else if (line == "TRAP")
    {
        type = CardType::TRAP;
    }
    else
    {
        type = CardType::BUFF;
    }

    return type;
}
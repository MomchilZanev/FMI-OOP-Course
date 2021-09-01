#include "Duelist.hpp"

Duelist::Duelist(const std::string& name)
    :name(name)
{ }

bool Duelist::saveDeck(const std::string & fileName) const
{
    std::ofstream file;

    file.open(fileName);
    if (file.is_open())
    {
        file << this->deck.printFullDeck();

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

Deck& Duelist::getDeck()
{
    return this->deck;
}

void Duelist::duel(Duelist& opponent)
{
    if (this->getDeck().getCardsCount() != opponent.getDeck().getCardsCount())
    {
        std::cout << "Duel cannot commence! Duelists need to have same cards count." << std::endl;
        return;
    }
    
    this->getDeck().shuffle();
    opponent.getDeck().shuffle();

    std::pair<unsigned, unsigned> result = this->getDeck().compareDecks(opponent.getDeck());
    unsigned currentPoints = result.first;
    unsigned opponentPoints = result.second;

    std::cout << "Duel result - ";    
    if (currentPoints > opponentPoints)
    {
        std::cout << this->getName() << " WINS!" << std::endl;
    }
    else if (currentPoints < opponentPoints)
    {
        std::cout << opponent.getName() << " WINS!" << std::endl;
    }
    else
    {
        std::cout << " DRAW" << std::endl;
    }
    std::cout << this->getName() << " - " << currentPoints << " points." << std::endl;
    std::cout << opponent.getName() << " - " << opponentPoints << " points." << std::endl;
}

void Duelist::changeName(const std::string& name)
{
    this->name = name;
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
    unsigned currentIndex = 0;

    std::string deckName = container[currentIndex++];
    unsigned cardsCount = std::stoi(container[currentIndex++]);
    unsigned monsterCardsCount = std::stoi(container[currentIndex++]);
    unsigned magicCardsCount = std::stoi(container[currentIndex++]);
    unsigned pendulumCardsCount = std::stoi(container[currentIndex++]);

    this->getDeck().setName(deckName);
    this->getDeck().clear();
    
    for (unsigned i = 0; i < monsterCardsCount; i++)
    {
        this->getDeck().addCard(&this->readMonsterCard(container, currentIndex));
    }

    for (unsigned i = 0; i < magicCardsCount; i++)
    {
        this->getDeck().addCard(&this->readMagicCard(container, currentIndex));
    }

    for (unsigned i = 0; i < pendulumCardsCount; i++)
    {
        this->getDeck().addCard(&this->readPendulumCard(container, currentIndex));
    }
}

MonsterCard Duelist::readMonsterCard(const std::vector<std::string>& container, unsigned& index)
{
    std::string name;
    std::string effect;
    unsigned rarity;
    unsigned attackPoints;
    unsigned defensePoints;
    this->getBaseInfo(container, index, name, effect, rarity);
    this->getAttackAndDefensePoints(container, index, attackPoints, defensePoints);

    return MonsterCard(name, effect, rarity, attackPoints, defensePoints);
}

MagicCard Duelist::readMagicCard(const std::vector<std::string>& container, unsigned& index)
{
    std::string name;
    std::string effect;
    unsigned rarity;
    this->getBaseInfo(container, index, name, effect, rarity);
    CardType type = this->getCardType(container[index++]);

    return MagicCard(name, effect, rarity, type);
}

PendulumCard Duelist::readPendulumCard(const std::vector<std::string>& container, unsigned& index)
{
    std::string name;
    std::string effect;
    unsigned rarity;
    unsigned attackPoints;
    unsigned defensePoints;
    unsigned pendulumScale;

    this->getBaseInfo(container, index, name, effect, rarity);
    this->getAttackAndDefensePoints(container, index, attackPoints, defensePoints);
    pendulumScale = std::stoi(container[index++]);
    CardType type = this->getCardType(container[index++]);

    return PendulumCard(name, effect, rarity, attackPoints, defensePoints, pendulumScale, type);
}

void Duelist::getBaseInfo(const std::vector<std::string>& container, unsigned& index, std::string& name, std::string& effect, unsigned& rarity)
{
    name = container[index++];
    effect = container[index++];
    rarity = std::stoi(container[index++]);
}

void Duelist::getAttackAndDefensePoints(const std::vector<std::string>& container, unsigned& index, unsigned& attackPoints, unsigned& defensePoints)
{
    attackPoints = std::stoi(container[index++]);
    defensePoints = std::stoi(container[index++]);
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
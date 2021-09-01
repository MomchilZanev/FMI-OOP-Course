#include <iostream>
#include "Duelist.hpp"
#include <map>
using namespace std;

int main()
{
    std::map<Type, string> typeMap;
    typeMap[spell] = "Spell";
    typeMap[trap] = "Trap";
    typeMap[buff] = "Buff";

    MagicCard magic1("Reflection", "Reflects the last played spell", trap);
    cout << magic1.getName() << ", " << magic1.getEffect() << ", " << typeMap[magic1.getType()] << endl;
    MagicCard magic2("Monster reborn", "revive", spell);
    cout << magic2.getName() << ", " << magic2.getEffect() << ", " << typeMap[magic2.getType()] << endl;

    MonsterCard monster1("Dark Magician", 2500, 2100);
    cout << monster1.getName() << ", " << monster1.getAttackPoints() << ", " << monster1.getDefensePoints() << endl;
    MonsterCard monster2("Blue-eyes white dragon", 3000, 2500);
    cout << monster2.getName() << ", " << monster2.getAttackPoints() << ", " << monster2.getDefensePoints() << endl;

    cout << endl;

    Duelist duelist1 = Duelist("Seto Kaiba");
    cout << duelist1.getName() << endl;
    duelist1.changeMagicCardInDeck(10, magic2);    
    duelist1.addMagicCardToDeck(magic1);
    cout << "Magic cards:" << duelist1.getMonsterCardCountInDeck() << endl;
    cout << "Monster cards:" << duelist1.getMagicCardCountInDeck() << endl;

    cout << endl;

    Duelist duelist2 = Duelist("Yugi Muto");
    duelist2.setName("Yugi Muto 2");
    cout << duelist2.getName() << endl;
    duelist2.changeMonsterCardInDeck(19, monster2);
    duelist2.addMonsterCardToDeck(monster1);
    duelist2.changeMonsterCardInDeck(0, MonsterCard("Dark Magician BUFF", 5000, 4100));
    cout << "Magic cards:" << duelist2.getMagicCardCountInDeck() << endl;
    cout << "Monster cards:" << duelist2.getMonsterCardCountInDeck() << endl;
}
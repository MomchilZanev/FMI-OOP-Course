#include <iostream>
#include "Duelist.hpp"

int main()
{
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::TRAP);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, CardType::SPELL);
    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().changeName("Magician Deck");
    firstDuelist.getDeck().addMonsterCard(dragon);
    firstDuelist.getDeck().addMagicCard(swords);
    firstDuelist.getDeck().addMonsterCard(magician);
    firstDuelist.getDeck().addMagicCard(cylinder);
    firstDuelist.getDeck().addPendulumCard(timegazer);
    firstDuelist.display();
    firstDuelist.saveDeck("magician_deck.txt");
    MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL);
    firstDuelist.getDeck().changeMagicCard(1, box);

    PendulumCard test("Test", "Stuff", -150, -700, 30, CardType::BUFF);
    firstDuelist.getDeck().changePendulumCard(0, test);
    firstDuelist.loadDeck("magician_deck.txt");
    firstDuelist.display();

    MonsterCard monster("Monster", "Stuff", 1, 1);
    MagicCard magic("Magic", "Magic stuff", CardType::SPELL);
    PendulumCard pendulum("Pendulum", "Other stuff", 2, 3, 13, CardType::TRAP);
    Deck deck("Boring deck");
    deck.addMonsterCard(monster);
    deck.addMagicCard(magic);
    deck.addPendulumCard(pendulum);
    Duelist duelist2("Gosho Peshov", deck);
    Deck emtyDeck;
    duelist2.setDeck(emtyDeck);
}
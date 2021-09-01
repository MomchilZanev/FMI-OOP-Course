#include <iostream>
#include "Duelist.hpp"

int main()
{
    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::SPELL);
    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().setName("Magician Deck");
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.getDeck().addCard(&swords);
    firstDuelist.getDeck().addCard(&magician);
    firstDuelist.getDeck().addCard(&cylinder);
    firstDuelist.getDeck().addCard(&timegazer);
    firstDuelist.getDeck().shuffle();
    std::cout << firstDuelist.getDeck().printFullDeck() << std::endl;
    firstDuelist.saveDeck("magician_deck.txt");
    firstDuelist.loadDeck("magician_deck.txt");
    std::cout << firstDuelist.getDeck().printFullDeck() << std::endl;
    MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::BUFF);
    firstDuelist.getDeck().changeCard(2, &box);
    std::cout << firstDuelist.getDeck().printFullDeck() << std::endl;

    Duelist secondDuelist("Gosho Goshev");
    secondDuelist.getDeck().addCard(&dragon);
    secondDuelist.getDeck().addCard(&swords);
    secondDuelist.getDeck().addCard(&magician);
    secondDuelist.getDeck().addCard(&cylinder);
    secondDuelist.getDeck().addCard(&timegazer);

    firstDuelist.duel(secondDuelist);
    secondDuelist.duel(firstDuelist);

    firstDuelist.getDeck().clear();

    Deck deck1("Deck 1");
    deck1.addCard(&dragon);
    deck1.addCard(&swords);
    deck1.addCard(&magician);
    deck1.addCard(&cylinder);
    deck1.addCard(&timegazer);

    Deck deck2 = deck1;
    deck2 = deck1;

    secondDuelist = firstDuelist;
    Duelist thirdDuelist = secondDuelist;
}
#include <iostream>
#include "Inventory.hpp"
#include "Equipment.hpp"
#include "Backpack.hpp"
#include "Materials.hpp"
#include "Money.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"

void armorTests()
{
	Armor defaultClothArmor;
	Armor leatherArmor(ArmorType::leather, 25);
	Armor chainmailArmor(ArmorType::mail, -45); // Defense: 45

	leatherArmor.changeDefense(-35); // Defense: 35
	leatherArmor.print();

	leatherArmor.addEffect("Style", 1000);
	leatherArmor.addEffect("Fire Resist", 78.63);
	leatherArmor.addEffect("Frost Resist", 37.66);
	leatherArmor.addEffect("Water Proof", 0.1735);
	leatherArmor.print();

	leatherArmor.addEffect("Fire Resist", 36.41);
	leatherArmor.changeEffectPower("Frost Resist", 81.27345);
	leatherArmor.removeEffect("Water Proof");
	leatherArmor.removeEffect("Water Proof");
	leatherArmor.print();

	bool t1 = defaultClothArmor == leatherArmor; // false
	bool t2 = defaultClothArmor == Armor(ArmorType::cloth, 10); // true
	bool t3 = defaultClothArmor == Armor(ArmorType::cloth, 20); // false
	defaultClothArmor.addEffect("Speed", 12.32);
	bool t4 = defaultClothArmor == Armor(ArmorType::cloth, 10); // false
}

void weaponTests()
{
	Weapon defaultShortsword;
	Weapon longsword(WeaponType::twoHanded, WeaponCategory::sword, 100, 150);
	Weapon staff(WeaponType::twoHanded, WeaponCategory::staff, 10.75, 200.24);
	Weapon dagger(WeaponType::oneHanded, WeaponCategory::dagger, 60.55, 70.89);
	Weapon badInput(WeaponType::oneHanded, WeaponCategory::staff, 100, 80); // one-handed, sword, hit-low:80, hit-high:100

	dagger.addEffect("Bleeding", 15.35);
	dagger.addEffect("Sparkles", 0.15);
	dagger.addEffect("Poison", 7.75);
	dagger.print();

	dagger.addEffect("Bleeding", 35.45);
	dagger.changeEffectPower("Poison", 10.25);
	dagger.removeEffect("Sparkles");
	dagger.removeEffect("Nonexistant");
	dagger.print();
	
	longsword.changeHitDamage(150, 200);
	longsword.print();

	staff.changeWeaponType(WeaponType::oneHanded); // one-handed sword
	staff.changeWeaponCategory(WeaponCategory::mace); // one-handed mace
	staff.changeWeaponCategory(WeaponCategory::staff); // two-handed staff

	bool t1 = defaultShortsword == longsword; // false
	bool t2 = defaultShortsword == Weapon(WeaponType::oneHanded, WeaponCategory::sword, 25.0, 75); // true
	bool t3 = defaultShortsword == Weapon(WeaponType::oneHanded, WeaponCategory::sword, 90, 40); // false
}

void moneyTests()
{
	Money bigPouch(9876, 0); // 76 silver, 98 gold
	bigPouch.clearAll();

	Money emptyMoneybag;
	Money moneybag(89, 3);

	emptyMoneybag.print();
	int s1 = emptyMoneybag.slotsOccupied(); // 0
	bool t1 = emptyMoneybag.isEmpty(); // true
	bool t2 = emptyMoneybag.isFull(); // false
	bool t3 = moneybag.isEmpty(); //false
	
	int s2 = moneybag.slotsOccupied(); // 1
	moneybag.print();
	moneybag.add(Money(-11, -1)); // 11 silver, 1 gold
	moneybag.print();
	moneybag.remove(Money(125, 1));
	moneybag.print();
	moneybag.remove(Money(125123, 1123));
	moneybag.print();
}

void materialsTests()
{
	Materials fullEssence(0, 0, 0, 160);
	Materials fullOres(0, 320, 0, 0);
	bool t1 = fullEssence.isFull() && fullOres.isFull() && !fullEssence.isEmpty() && !fullOres.isEmpty(); // true
	Materials invalidinput1(321, 0, 0, 0); // Empty
	Materials invalidinput2(0, 0, 0, -161); // 161 Empty
	bool t2 = invalidinput1.isEmpty() && invalidinput2.isEmpty() && !invalidinput1.isFull() && !invalidinput2.isFull(); // true

	fullOres.add(Materials(1, 0, 0, 0));
	fullOres.remove(Materials(10, 10, 10, 10));
	bool t3 = fullOres.isFull(); // false
	fullOres.add(Materials(0, 10, 0, 0));

	Materials materialsBag(28, 20, 1, 34); // 2 + 1 + 1 + 4 slots
	materialsBag.print();
	materialsBag.add(Materials(12, 15, 20, 7)); // 2 + 2 + 2 + 5 slots
	materialsBag.print();
	materialsBag.remove(Materials(0, 5, 1, 1)); // 2 + 2 + 1 + 4 slots
	materialsBag.print();
	materialsBag.add(Materials(60, 60, 60, 70));
	materialsBag.print();
	materialsBag.remove(Materials(60, 60, 60, 70)); // Empty
}

void backpackTests()
{
	auto moneyDef = Backpack<Money>(Money());
	auto materialsDef = Backpack<Materials>(Materials());
	bool t1 = moneyDef.isEmpty(); // true
	t1 = moneyDef.isFull(); // false
	t1 = materialsDef.isEmpty(); // true
	t1 = materialsDef.isFull(); // false;

	auto moneyBackpack = Backpack<Money>(Money(75, 1));
	auto materialsBackpack = Backpack<Materials>(Materials(5, 19, 23, 14));
	moneyBackpack.print();
	materialsBackpack.print();
	bool t2 = moneyBackpack.isEmpty(); // false
	t2 = moneyBackpack.isFull(); // false
	t2 = materialsBackpack.isEmpty(); // false
	t2 = materialsBackpack.isFull(); // false;

	moneyBackpack.clear();
	materialsBackpack.clear();
	moneyBackpack.print();
	materialsBackpack.print();

	moneyBackpack.add(Money(1074, 70));
	materialsBackpack.add(Materials(25,35,45,65));
	moneyBackpack.print();
	materialsBackpack.print();

	moneyBackpack.remove(Money(-63, -75)); // 63 75
	materialsBackpack.remove(Materials(5, 3, 15, 20));
	moneyBackpack.print();
	materialsBackpack.print();

	materialsBackpack.add(Materials(0, 8, 10, 65)); // Full
	materialsBackpack.print();
	materialsBackpack.add(Materials(1, 1, 1, 1)); // Fail
	materialsBackpack.print();
}

void equipmentTests()
{
	Equipment<Armor> wardrobe;
	Equipment<Weapon> armory;
	bool t1 = wardrobe.isEmpty(); // true
	t1 = wardrobe.isFull(); // false
	t1 = armory.isEmpty(); // true
	t1 = armory.isFull(); // false

	Armor leatherArmor(ArmorType::leather, 30);
	leatherArmor.addEffect("Agility", 25);
	leatherArmor.addEffect("Strength", 10);
	wardrobe.add(leatherArmor);
	wardrobe.add(Armor(ArmorType::mail, 45));
	wardrobe.print();
	std::cout << "\nBest item: ";
	wardrobe.getBestEquipment().print();

	Weapon twohandedMace(WeaponType::twoHanded, WeaponCategory::mace, 70.63, 81.92);
	twohandedMace.addEffect("Bludgeoning", 55.75);
	twohandedMace.addEffect("Internal Bleeding", 43.0897);
	armory.add(twohandedMace);
	armory.add(Weapon(WeaponType::oneHanded, WeaponCategory::dagger, 98, 100.7543));
	armory.add(Weapon(WeaponType::oneHanded, WeaponCategory::dagger, 98, 100.7543)); // Duplicates are allowed
	armory.print();
	std::cout << "\nBest item: ";
	armory.getBestEquipment().print();

	wardrobe.remove(Armor(ArmorType::mail, 45));
	armory.remove(Weapon(WeaponType::oneHanded, WeaponCategory::dagger, 98, 100.7543)); // Only first encountered is deleted

	for (int i = 0; i < 25; i++)
	{
		wardrobe.add(Armor()); // only 23 added
		armory.add(Weapon(WeaponType::twoHanded, WeaponCategory::sword, 20, 20)); // only 12 added
	}

	wardrobe.clear();
	armory.clear();

	Equipment<Armor> wardrobe2;
	bool t2 = wardrobe == wardrobe2 && !(wardrobe != wardrobe2); // true;
	Armor clothArmor = Armor(ArmorType::cloth, 25);
	clothArmor.addEffect("Test", 123);
	wardrobe2.add(clothArmor);
	t2 = wardrobe == wardrobe2 && !(wardrobe != wardrobe2); // false;

	Equipment<Weapon> armory2;
	t2 = armory == armory2 && !(armory != armory2); // true;
	armory.add(Weapon(WeaponType::twoHanded, WeaponCategory::staff, 73, 89));
	t2 = armory == armory2 && !(armory != armory2); // false;	
}

void inventoryTests()
{
	Equipment<Armor> wardrobeEmpty;
	Equipment<Armor> wardrobe1;
	Equipment<Armor> wardrobe2;
	Armor leatherArmor(ArmorType::leather, 30);
	leatherArmor.addEffect("Agility", 25);
	leatherArmor.addEffect("Strength", 10);
	wardrobe1.add(leatherArmor);
	wardrobe2.add(Armor(ArmorType::mail, 980));
	Inventory<Equipment<Armor>, Armor> invEqAr1(wardrobeEmpty);
	Inventory<Equipment<Armor>, Armor> invEqAr2(wardrobe1);
	Inventory<Equipment<Armor>, Armor> invEqAr3(wardrobe2);
	std::cout << invEqAr2 << std::endl;
	bool t1 = invEqAr1 == invEqAr2; // false
	t1 = invEqAr1 != invEqAr3; // true
	t1 = invEqAr2 != invEqAr3; // false
	t1 = invEqAr1.isEmpty(); // true
	Armor armorToAdd(ArmorType::cloth, 5);
	invEqAr1.add(armorToAdd);
	invEqAr1.add(armorToAdd);
	invEqAr1.remove(armorToAdd);
	t1 = invEqAr1.isFull(); // false
	invEqAr1.clear();

	Equipment<Weapon> armoryEmpty;
	Equipment<Weapon> armory1;
	Equipment<Weapon> armory2;
	Weapon twohandedMace(WeaponType::twoHanded, WeaponCategory::mace, 70.63, 81.92);
	twohandedMace.addEffect("Bludgeoning", 55.75);
	twohandedMace.addEffect("Internal Bleeding", 43.0897);
	armory1.add(twohandedMace);
	armory2.add(Weapon(WeaponType::oneHanded, WeaponCategory::sword, 23, 34));
	Inventory<Equipment<Weapon>, Weapon> invEqWe1(armoryEmpty);
	Inventory<Equipment<Weapon>, Weapon> invEqWe2(armory1);
	Inventory<Equipment<Weapon>, Weapon> invEqWe3(armory2);
	std::cout << invEqWe2 << std::endl;
	bool t2 = invEqWe1 == invEqWe2; // false
	t2 = invEqWe2 != invEqWe3; // true
	t2 = invEqWe3 == invEqWe2; // false
	t2 = invEqWe1.isEmpty(); // true
	Weapon weaponToAdd(WeaponType::oneHanded, WeaponCategory::mace, 23, 63);
	invEqWe1.add(weaponToAdd);
	invEqWe1.add(weaponToAdd);
	invEqWe1.remove(weaponToAdd);
	t2 = invEqWe1.isFull(); // false
	invEqWe1.clear();

	Backpack<Money> moneyBackpack1(Money(75, 1)); // 1 slot 
	Backpack<Money> moneyBackpack2(Money(0, 0)); // 0 slots
	Backpack<Money> moneyBackpack3(Money(28, 3)); // 1 slot
	Inventory<Backpack<Money>, Money> invBpMo1(moneyBackpack1);
	Inventory<Backpack<Money>, Money> invBpMo2(moneyBackpack2);
	Inventory<Backpack<Money>, Money> invBpMo3(moneyBackpack3);
	std::cout << invBpMo3 << std::endl;
	bool t3 = invBpMo2 == invBpMo1; // false
	t3 = invBpMo1 == invBpMo3; // true (moneybags are compared by slots not by value)
	t3 = invBpMo3 != invBpMo1; // false

	Backpack<Materials> materialsBackpack1(Materials(5, 19, 23, 14));
	Backpack<Materials> materialsBackpack2(Materials(5, 19, 23, 14));
	Backpack<Materials> materialsBackpack3(Materials(0, 0, 23, 14));
	Inventory<Backpack<Materials>, Materials> invBpMa1(materialsBackpack1);
	Inventory<Backpack<Materials>, Materials> invBpMa2(materialsBackpack2);
	Inventory<Backpack<Materials>, Materials> invBpMa3(materialsBackpack3);
	std::cout << invBpMa1 << std::endl;
	bool t4 = invBpMa1 != invBpMa2; // false
	t4 = invBpMa2 == invBpMa1; // true
	t4 = invBpMa3 == invBpMa2; // false
}

int main()
{
	weaponTests();
	armorTests();
	moneyTests();
	materialsTests();
	backpackTests();
	equipmentTests();
	inventoryTests();
}
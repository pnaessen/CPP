/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:00:00 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/02 17:16:04 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

void printSeparator(const std::string& testName) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "TEST: " << testName << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void testBasicFunctionality() {
	printSeparator("BASIC FUNCTIONALITY (from subject)");
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

void testMateriaSourceLimits() {
	printSeparator("MATERIA SOURCE LIMITS (4 materias max)");
	
	IMateriaSource* src = new MateriaSource();
	
	std::cout << "\n--- Learning 4 materias ---" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << "\n--- Trying to learn 5th materia (should be ignored) ---" << std::endl;
	src->learnMateria(new Ice());
	
	std::cout << "\n--- Creating materias ---" << std::endl;
	AMateria* ice1 = src->createMateria("ice");
	AMateria* cure1 = src->createMateria("cure");
	AMateria* unknown = src->createMateria("fire");
	
	std::cout << "Ice created: " << (ice1 ? "YES" : "NO") << std::endl;
	std::cout << "Cure created: " << (cure1 ? "YES" : "NO") << std::endl;
	std::cout << "Fire created: " << (unknown ? "YES" : "NO") << std::endl;
	
	delete ice1;
	delete cure1;
	//delete unknown; //NULL
	delete src;
}

void testCharacterInventory() {
	printSeparator("CHARACTER INVENTORY TESTS");
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* hero = new Character("Hero");
	ICharacter* target = new Character("Target");
	
	std::cout << "\n--- Equipping 4 materias ---" << std::endl;
	hero->equip(src->createMateria("ice"));
	hero->equip(src->createMateria("cure"));
	hero->equip(src->createMateria("ice"));
	hero->equip(src->createMateria("cure"));
	
	std::cout << "\n--- Trying to equip 5th materia (should be ignored) ---" << std::endl;
	hero->equip(src->createMateria("ice"));
	
	std::cout << "\n--- Using all equipped materias ---" << std::endl;
	hero->use(0, *target);
	hero->use(1, *target);
	hero->use(2, *target);
	hero->use(3, *target);
	
	std::cout << "\n--- Invalid index tests ---" << std::endl;
	hero->use(-1, *target);
	hero->use(4, *target);
	
	std::cout << "\n--- Unequip tests ---" << std::endl;
	hero->unequip(1);
	hero->use(1, *target);
	
	hero->unequip(-1);
	hero->unequip(42);
	hero->unequip(1);
	
	delete target;
	delete hero;
	delete src;
}

void testDeepCopy() {
	printSeparator("DEEP COPY TESTS");
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << "\n--- Character copy constructor ---" << std::endl;
	Character original("Original");
	original.equip(src->createMateria("ice"));
	original.equip(src->createMateria("cure"));
	
	Character copy(original);
	std::cout << "Original name: " << original.getName() << std::endl;
	std::cout << "Copy name: " << copy.getName() << std::endl;
	
	std::cout << "\n--- Character assignment operator ---" << std::endl;
	Character assigned("Assigned");
	assigned = original;
	std::cout << "Assigned name: " << assigned.getName() << std::endl;
	
	ICharacter* dummy = new Character("Dummy");
	std::cout << "\n--- Testing independence of copies ---" << std::endl;
	original.use(0, *dummy);
	copy.use(0, *dummy);
	assigned.use(0, *dummy);
	
	delete dummy;
	delete src;
}

void testMateriaSourceCopy() {
	printSeparator("MATERIA SOURCE COPY TESTS");
	
	std::cout << "\n--- Original MateriaSource ---" << std::endl;
	MateriaSource original;
	original.learnMateria(new Ice());
	original.learnMateria(new Cure());
	
	std::cout << "\n--- Copy constructor ---" << std::endl;
	MateriaSource copy(original);
	
	std::cout << "\n--- Assignment operator ---" << std::endl;
	MateriaSource assigned;
	assigned = original;
	
	std::cout << "\n--- Testing all copies can create materias ---" << std::endl;
	AMateria* ice1 = original.createMateria("ice");
	AMateria* ice2 = copy.createMateria("ice");
	AMateria* ice3 = assigned.createMateria("ice");
	
	std::cout << "Original created ice: " << (ice1 ? "YES" : "NO") << std::endl;
	std::cout << "Copy created ice: " << (ice2 ? "YES" : "NO") << std::endl;
	std::cout << "Assigned created ice: " << (ice3 ? "YES" : "NO") << std::endl;

	delete ice1;
	delete ice2;
	delete ice3;
}

void testMemoryManagement() {
	printSeparator("MEMORY MANAGEMENT TESTS");
	
	std::cout << "\n--- Testing unequip doesn't delete materia ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	
	Character* hero = new Character("Hero");
	AMateria* ice = src->createMateria("ice");
	
	
	hero->equip(ice); 
	hero->unequip(0);
	
	ICharacter* target = new Character("Target");
	ice->use(*target);
	
	delete target;
	delete hero;
	delete src;
}

void testNullPointers() {
	printSeparator("NULL POINTER SAFETY TESTS");
	
	IMateriaSource* src = new MateriaSource();
	ICharacter* character = new Character("Test");
	
	std::cout << "\n--- Testing null materia handling ---" << std::endl;
	src->learnMateria(NULL);
	character->equip(NULL);
	
	std::cout << "NULL safety tests passed!" << std::endl;
	
	delete character;
	delete src;
}

void testLimit() {
	
	printSeparator("LIMIT TESTS");
	
	Character hero("Hero");
	AMateria* ice = new Ice();
	
	for (int i = 0; i < 6; i++) {
		hero.equip(ice);
	}
	std::cout << "============== Finished spam equip! ====================" << std::endl;

	Character loot("Loot");

	for (int i = 0; i < 11; ++i) {
		loot.equip(new Ice());
		loot.unequip(0);
		if (i == 9) std::cout << "=== Ground full, testing overflow ===" << std::endl;
	}

	std::cout << "============== Finished limit tests! ====================" << std::endl;
}

int main() {
	std::cout << "Starting tests" << std::endl;
	
	testBasicFunctionality();
	testMateriaSourceLimits();
	testCharacterInventory();
	testDeepCopy();
	testMateriaSourceCopy();
	testMemoryManagement();
	testNullPointers();
	testLimit();
	return 0;
}
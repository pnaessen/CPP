/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:02 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 12:14:31 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void printSeparator(const std::string& testName) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "TEST: " << testName << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void testDeepCopy() {
	
	std::cout << "===== TEST COPIE CONSTRUCTEUR =====" << std::endl; 
	
	Dog first;
	first.getBrain()->setIdeas(0, "Woof first");
	Dog copy(first);
	std::cout << "Idea de first : " << first.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Idea de copy : " << copy.getBrain()->getIdeas(0) << std::endl; 

	first.getBrain()->setIdeas(0, "Woof first got a new idea");
	std::cout << "Idea de first : " << first.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Idea de copy : " << copy.getBrain()->getIdeas(0) << std::endl;
	std::cout << std::endl;
}

void testOP() {

	std::cout << "===== TEST OP  =====" << std::endl;
	
	Dog dog1;
	Dog dog2;
	
	dog1.getBrain()->setIdeas(0, "dog1 Woof");
	dog2.getBrain()->setIdeas(0, "dog2 Woof");
	
	std::cout << "Idea de dog1 : " << dog1.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Idea de dog2 : " << dog2.getBrain()->getIdeas(0) << std::endl;

	dog2 = dog1;
	std::cout << "Idea de dog2 : " << dog2.getBrain()->getIdeas(0) << std::endl;
	
	dog1.getBrain()->setIdeas(0, "dog1 Woof new idea woof");
	std::cout << "Idea de dog1 : " << dog1.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Idea de dog2 : " << dog2.getBrain()->getIdeas(0) << std::endl;
	
}

void testFunction() {
	
	std::cout << "\n========== TEST FUNCTION ==========\n" << std::endl;

	Dog woaf;
	Cat mepris;
	const WrongAnimal  *pig = new WrongCat();
	
	
	std::cout << woaf.getType() << " " << std::endl;
	std::cout << mepris.getType() << " " << std::endl;
	woaf.makeSound();
	mepris.makeSound();
	
	std::cout << "\n========== TEST WRONG FUNCTION ==========\n" << std::endl;
	std::cout << pig->getType()<< " " << std::endl;
	pig->makeSound();
	
	std::cout << "\n========== DESTRUCTEURS ==========\n" << std::endl;

	delete pig;
}

void testBasic() {
	
	printSeparator("Basic Test");

	std::cout << "\n========== CONSTRUCTEURS ==========\n" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\n========== CONSTRUCTEURS TAB ==========\n" << std::endl;
	
	const Animal *tab[6];
	for(int i = 0; i < 6; i++) {
		if(i < 6 / 2) {
			tab[i] = new Dog();
		}
		else 
			tab[i] = new Cat();
	}
	std::cout << std::endl;
	
	std::cout << "\n========== TEST FUNSTION MAIN ==========\n" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << "\n========== DESTRUCTEURS MAIN ==========\n" << std::endl;
	delete i;
	delete j;
	
	std::cout << "\n========== DESTRUCTEURS TAB ==========\n" << std::endl;

	for(int i = 0; i < 6;i++) {
		delete tab[i];
	}
}

int main()
{


	std::cout << "\n========== TEST CLASSE ABSTRAITE ==========\n" << std::endl;

	#define TEST_ABSTRACT 0
	#if TEST_ABSTRACT
		Animal test;
		Animal* meta = new Animal();
	#endif
	
	std::string input;
	while(1) {
		if (!std::cin.eof()) {
			std::cout << std::endl << RED << "PLEASE CHOOSE BETWEEN THESE TEST :" << std::endl
			<< "	1 - Basic test" << std::endl
			<< "	2 - Asign test" << std::endl
			<< "	3 - Copie test" << std::endl
			<< "	4 - Function test" << std::endl
			<< "	X - exit" << RESET << std::endl << std::endl;
		}
		if (!(std::cin >> input))
		{
			std::cout << "Error, exit program" << std::endl;
			return (1);
		}
		if (input == "1")
			testBasic();
		else if (input == "2")
			testOP();
		else if (input == "3")
			testDeepCopy();
		else if (input == "4")
			testFunction();
		else if (input == "X" || input == "x" )
			return 0;
		else
			std::cout << "Please choose a valid test" << std::endl;
	}
	return 0;
}
	

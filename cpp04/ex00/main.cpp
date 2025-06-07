/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:02 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 10:47:17 by pnaessen         ###   ########lyon.fr   */
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

void testBasic() {

	printSeparator("BASIC FUNCTIONALITY");

	std::cout << "\n========== CONSTRUCTEURS ==========\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal  *wrong = new WrongCat();
	
	std::cout << "\n========== TEST FUNCTION ==========\n" << std::endl;

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n========== TEST WRONG FUNCTION ==========\n" << std::endl;
	std::cout<<wrong->getType()<< " " << std::endl;
	wrong->makeSound();

	std::cout << "\n========== DESTRUCTEURS ==========\n" << std::endl;
	delete wrong;
	delete i;
	delete j;
	delete meta;	
}

void testAsign() {
	
	Dog woof;
	Dog asign;
	asign = woof;

	std::cout << std::endl;
	
	Cat mew;
	Cat casign;
	casign = mew;

	std::cout << std::endl;
}

void testCopie() {
	Cat mepris;
	Cat copie(mepris);

	std::cout << std::endl;

	Dog silly;
	Dog dcopie(silly);

	std::cout << std::endl;
}

int main()
{

	std::string input;
	while(1) {
		if (!std::cin.eof()) {
			std::cout << std::endl << RED << "PLEASE CHOOSE BETWEEN THESE TEST :" << std::endl
			<< "	1 - Basic test" << std::endl
			<< "	2 - Asign test" << std::endl
			<< "	3 - Copie test" << std::endl
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
			testAsign();
		else if (input == "3")
			testCopie();
		else if (input == "X" || input == "x" )
			return 0;
		else
			std::cout << "Please choose a valid test" << std::endl;
	}
	return 0;
}

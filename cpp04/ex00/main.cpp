/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:02 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/20 07:42:50 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n========== CONSTRUCTEURS ==========\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal  *wrong = new WrongCat();
	
	std::cout << "\n========== TEST FUNCTION ==========\n" << std::endl;

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
	return 0;
}

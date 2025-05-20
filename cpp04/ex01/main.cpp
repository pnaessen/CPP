/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:24:02 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/20 14:06:49 by pnaessen         ###   ########lyon.fr   */
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
	
	std::cout << "===== TEST COPIE CONSTRUCTEUR =====" << std::endl; 
	
	Dog *first = new Dog();
	first->getBrain()->setIdeas(0, "Woof first");
	Dog *copy = new Dog(*(first));
	std::cout << "Idea de first : " << first->getBrain()->getIdeas(0) << std::endl;
	std::cout << "Idea de copy : " << first->getBrain()->getIdeas(0) << std::endl; 

	first->getBrain()->setIdeas(0, "Woof first got a new idea");
	std::cout << "Idea de first : " << first->getBrain()->getIdeas(0) << std::endl;
	std::cout << "Idea de copy : " << first->getBrain()->getIdeas(0) << std::endl;
	delete first;
	delete copy;
	std::cout << std::endl;


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
	
	std::cout << "\n========== DESTRUCTEURS TAB ==========\n" << std::endl;

	for(int i = 0; i < 6;i++) {
		delete tab[i];
	}
	return 0;
}

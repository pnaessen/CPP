/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/21 15:44:20 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor call" <<std::endl;
	type = "Dog";
	ideas = new Brain();
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	std::cout << "Dog copy constructor" << std::endl;
	ideas = new Brain(*(obj.ideas));
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog copy assignment operator" << std::endl;
	if(this != &obj) {
		Animal::operator=(obj);
		delete ideas;
		ideas = new Brain(*(obj.ideas));
	}
	return *this;
}

Dog::~Dog() {
	delete ideas;
	std::cout << "Dog destructor call" <<std::endl;

}

void Dog::makeSound() const {
	std::cout << "Wooooooooooooooooooooooooooof" << std::endl;
}

Brain* Dog::getBrain() {
	return this->ideas;
}

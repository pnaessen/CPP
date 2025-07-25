/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 11:02:38 by pnaessen         ###   ########lyon.fr   */
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
	if(this != &obj) {
		Animal::operator=(obj);
		std::cout << "Dog copy assignment operator" << std::endl;
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

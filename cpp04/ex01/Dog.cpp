/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 18:37:06 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Animal constructor call" <<std::endl;
	type = "Dog";
	ideas = new Brain();
}

Dog::Dog(Dog& obj) : Animal(obj) {
	std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(Dog& obj) {
	
	std::cout << "Dog copy assignment operator" << std::endl;
	if(this != &obj)
		Animal::operator=(obj);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor call" <<std::endl;
	delete ideas;

}

void Dog::makeSound() const {
	std::cout << "Wooooooooooooooooooooooooooof" << std::endl;
}
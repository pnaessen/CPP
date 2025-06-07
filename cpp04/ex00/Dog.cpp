/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:28:07 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 10:43:25 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor call" <<std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& obj) : Animal(obj) {
	std::cout << "Dog copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& obj) {
	if(this != &obj)
		Animal::operator=(obj);
	std::cout << "Dog asign assignment operator" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor call" <<std::endl;

}

void Dog::makeSound() const {
	std::cout << "Wooooooooooooooooooooooooooof" << std::endl;
}
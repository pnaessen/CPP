/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:39:37 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 11:04:33 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor call" <<std::endl;
	type = "Cat";
	ideas = new Brain();
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	std::cout << "Cat copy constructor" << std::endl;
	ideas = new Brain(*(obj.ideas));
}

Cat& Cat::operator=(const Cat& obj) {
	
	if(this != &obj) {
		Animal::operator=(obj);
		std::cout << "Cat copy assignment operator" << std::endl;
		delete ideas;
		ideas = new Brain(*(obj.ideas));
		}
	return *this;

}

Cat::~Cat() {
	delete ideas;
	std::cout << "Cat destructor call" <<std::endl;

}

void Cat::makeSound() const{
	std::cout << "Meooooooooooooooooooooooooooooooooooooooooooooow" << std::endl;
}

Brain* Cat::getBrain() {
	return this->ideas;
}
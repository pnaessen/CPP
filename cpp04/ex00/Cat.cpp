/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:39:37 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/21 15:43:10 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor call" <<std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& obj) : Animal(obj) {
	std::cout << "Cat copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if(this != &obj)
		Animal::operator=(obj);
	return *this;

}

Cat::~Cat() {
	std::cout << "Cat destructor call" <<std::endl;

}

void Cat::makeSound() const{
	std::cout << "Meooooooooooooooooooooooooooooooooooooooooooooow" << std::endl;
}
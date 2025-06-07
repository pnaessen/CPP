/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:39:37 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 10:43:19 by pnaessen         ###   ########lyon.fr   */
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
	if(this != &obj)
		Animal::operator=(obj);
	std::cout << "Cat asign assignment operator" << std::endl;
	return *this;

}

Cat::~Cat() {
	std::cout << "Cat destructor call" <<std::endl;

}

void Cat::makeSound() const{
	std::cout << "Meooooooooooooooooooooooooooooooooooooooooooooow" << std::endl;
}
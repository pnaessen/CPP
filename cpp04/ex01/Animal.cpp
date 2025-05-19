/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:25 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 17:29:59 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor call" <<std::endl;
	type = "GRUIK";
}

Animal::Animal(Animal& obj) {
	std::cout << "Animal copy constructor operator" << std::endl;
	*this = obj;
}

Animal::~Animal() {
	std::cout << "Animal destructor call" <<std::endl;
}

Animal& Animal::operator=(Animal& obj) {
	
	std::cout << "Animal copy assignment operator" << std::endl;
	if(this != &obj)
		type = obj.type;
	return *this;
}

void Animal::makeSound() const{
	std::cout << "Animal goes ZBRRRRRR" << std::endl;
}

std::string Animal::getType() const {
	return type;
}
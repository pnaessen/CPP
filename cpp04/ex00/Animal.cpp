/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:25:25 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/07 10:43:14 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor call" <<std::endl;
	type = "GRUIK";
}

Animal::Animal(const Animal& obj) : type(obj.type) {
	std::cout << "Animal copy constructor operator" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor call" <<std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
	if(this != &obj)
		type = obj.type;
	std::cout << "Animal asign assignment operator" << std::endl;
	return *this;
}

void Animal::makeSound() const{
	std::cout << "Animal goes ZBRRRRRR" << std::endl;
}

std::string Animal::getType() const {
	return type;
}
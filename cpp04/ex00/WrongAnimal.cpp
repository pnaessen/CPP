/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:40:10 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 18:42:47 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor call" <<std::endl;
	type = "GRUIK";
}

WrongAnimal::WrongAnimal(WrongAnimal& obj) {
	std::cout << "WrongAnimal copy constructor operator" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor call" <<std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& obj) {
	
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	if(this != &obj)
		type = obj.type;
	return *this;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal goes ZBRRRRRR" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
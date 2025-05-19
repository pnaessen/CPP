/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:45:27 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 18:47:03 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "Animal constructor call" <<std::endl;
	type = "Cat";
}

WrongCat::WrongCat(WrongCat& obj) : WrongAnimal(obj) {
	std::cout << "Cat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& obj) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if(this != &obj)
	WrongAnimal::operator=(obj);
	return *this;

}

WrongCat::~WrongCat() {
	std::cout << "Cat destructor call" << std::endl;

}

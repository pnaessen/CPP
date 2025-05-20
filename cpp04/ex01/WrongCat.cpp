/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:45:27 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/20 07:43:46 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat constructor call" <<std::endl;
	type = "Cow with a irish accent";
}

WrongCat::WrongCat(WrongCat& obj) : WrongAnimal(obj) {
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat& obj) {
	std::cout << "WrongCat copy assignment operator" << std::endl;
	if(this != &obj)
		WrongAnimal::operator=(obj);
	return *this;

}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor call" << std::endl;

}

void WrongCat::makeSound() const {
	std::cout << "Mooooooooooooooooooooooooooooooooooooooooooooow where is my coffee" << std::endl;
}
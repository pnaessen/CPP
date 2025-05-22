/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:57:35 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 15:58:13 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria() {
	std::cout << "Ice constructor call" << std::endl;
	_type = "Ice";
}

Ice::Ice(std::string name) : AMateria(name) {
	std::cout << "Ice surcharge constructeur" << std::endl;	
}

Ice::Ice(const Ice& obj) : AMateria(obj) {
	std::cout << "Ice copy constructor" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor call" << std::endl;
}

Ice& Ice::operator=(const Ice&obj) {
	std::cout << "Ice operator  call" << std::endl;
	if(this != &obj) {
		AMateria::operator=(obj);
		_type = obj._type;
	}
	return *this;
}

void Ice::use(ICharacter& target) {
	
}

AMateria *Ice::clone() const {
	
}
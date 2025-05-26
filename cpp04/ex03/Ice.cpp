/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:57:35 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/26 12:06:16 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor call" << std::endl;
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
	}
	return *this;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:26:56 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 17:47:17 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor call" << std::endl;
}

Cure::Cure(std::string name) : AMateria(name) {
	std::cout << "Cure surcharge constructeur" << std::endl;	
}

Cure::Cure(const Cure& obj) : AMateria(obj) {
	std::cout << "Cure copy constructor" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor call" << std::endl;
}

Cure& Cure::operator=(const Cure&obj) {
	std::cout << "Cure operator  call" << std::endl;
	if(this != &obj) {
		AMateria::operator=(obj);
	}
	return *this;
}

void Cure::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}
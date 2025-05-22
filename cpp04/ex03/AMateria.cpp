/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 06:59:21 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 23:06:10 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria default constructeur" << std::endl;	
}

AMateria::AMateria(std::string const& type)  : _type(type) {
		std::cout << "AMateria surcharge constructeur" << std::endl;	
}

AMateria::AMateria(const AMateria& obj) : _type(obj._type){
	std::cout << "AMateria copy constructeur" << std::endl;	

}

AMateria::~AMateria() {
	std::cout << "AMateria  destructor" << std::endl;	

}

AMateria& AMateria::operator=(const AMateria& obj) {
	std::cout << "AMateria operator  call" << std::endl;
	_type = obj._type;
	return *this;	

}

std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:25:31 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 15:49:53 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter() {
	std::cout << "Character constructeur call" << std::endl;
}

Character::Character(const Character& obj) : ICharacter(obj) {
	std::cout << "Character copy constructeur" << std::endl;
	_name = obj._name;
}

Character::~Character() {
	std::cout << "Character destructeur call" << std::endl;	

}

Character& Character::operator=(const Character& obj) {
	std::cout << "Character operator  call" << std::endl;
	if(this != &obj) {
		ICharacter::operator=(obj);
		_name = obj._name;
	}
	return *this;
}

std::string const& Character::getName() {
	return _name;
}

void Character::equip(AMateria *m) {
	
}

void Character::unequip(int idx) {
	
}

void Character::use(int idx, ICharacter& target) {
	
}

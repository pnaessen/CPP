/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:25:31 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/23 13:07:30 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << "Character constructeur call" << std::endl;
	_name = "Another random";
	for(int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const std::string& name) : _name(name) {
	std::cout << "Character surcharge constructeur" << std::endl;
	for(int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(const Character& obj) {
	std::cout << "Character copy constructeur" << std::endl;
	_name = obj._name;
	for(int i = 0; i < 4; i++) {
		_inventory[i] =  NULL;
	}
	
	for(int i = 0; i < 4; i++) {
		if(obj._inventory[i] != NULL) {
			_inventory[i] = obj._inventory[i]->clone();
		}
	}
}

Character::~Character() {
	std::cout << "Character destructeur call" << std::endl;
	
	for(int i = 0; i < 4; i++) {
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& obj) {
	std::cout << "Character operator  call" << std::endl;

	if(this != &obj) {
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		_name = obj._name;
	
		for(int i = 0; i < 4; i++) {
			if(obj._inventory[i] != NULL) {
				_inventory[i] = obj._inventory[i]->clone();
			}
		}
	}
	return *this;
}

std::string const& Character::getName() const{
	return _name;
}

void Character::equip(AMateria *m) {
	if(!m)
		return;
	for(int i = 0; i < 4; i++) {
		if(!_inventory[i]) {
				_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
	if(idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if(idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

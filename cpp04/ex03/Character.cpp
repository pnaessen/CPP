/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:25:31 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/02 17:24:36 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	std::cout << "Character constructeur call" << std::endl;
	_name = "Another random";
	_groundCount = 0;
	for(int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	for(int i = 0; i < 10; i++) {
		_ground[i] = NULL;
	}
}

Character::Character(const std::string& name) : _name(name) {
	std::cout << "Character surcharge constructeur" << std::endl;
	for(int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	_groundCount = 0;
	for(int i = 0; i < 10; i++) {
		_ground[i] = NULL;
	}
}

Character::Character(const Character& obj) {
	std::cout << "Character copy constructeur" << std::endl;
	_name = obj._name;
	_groundCount = obj._groundCount;
	for(int i = 0; i < 4; i++) {
		_inventory[i] =  NULL;
	}
	
	for(int i = 0; i < 4; i++) {
		if(obj._inventory[i] != NULL) {
			_inventory[i] = obj._inventory[i]->clone();
		}
	}
	
	for(int i = 0; i < 10; i++) {
		if(obj._ground[i] != NULL) {
			_ground[i] = obj._ground[i]->clone();
		} else {
			_ground[i] = NULL;
		}
	}
}

Character::~Character() {
	
	for(int i = 0; i < 4; i++) {
		if(_inventory[i]) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	for(int i = 0; i < 10; i++) {
		if(_ground[i] != NULL) {
			delete _ground[i];
			_ground[i] = NULL;
		}
	}
	std::cout << "Character destructeur call" << std::endl;
}

Character& Character::operator=(const Character& obj) {
	std::cout << "Character operator  call" << std::endl;

	if(this != &obj) {
		for (int i = 0; i < 4; i++) {
			if(_inventory[i]) 
				delete _inventory[i];
			_inventory[i] = NULL;
		}
		
		for(int i = 0; i < 10; i++) {
			if(_ground[i]) {
				delete _ground[i];
			}
			_ground[i] = NULL;
		}
		
		_name = obj._name;
		_groundCount = obj._groundCount;
		
		for(int i = 0; i < 4; i++) {
			if(obj._inventory[i] != NULL) {
				_inventory[i] = obj._inventory[i]->clone();
			}
		}
		
		for(int i = 0; i < 10; i++) {
			if(obj._ground[i] != NULL) {
				_ground[i] = obj._ground[i]->clone();
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
		
		if(_inventory[i] == m) {
			std::cout << "Materia already equipped" << std::endl;
			return;
		}
		
		if(!_inventory[i]) {
				_inventory[i] = m;
				std::cout << _name << " equip a materia" << std::endl;
			return;
		}
	}
	delete m;
}

void Character::handle_groundFull(int idx) {
	
	std::cout << "Ground is full, materia destroy the ground" << std::endl;
	for (int i = 0; i < 10; i++) {
		if(_ground[i]) {
			delete _ground[i];
			_ground[i] = NULL;
			_groundCount--;
			std::cout << "Ground slot " << i << " cleared" << std::endl;
		}
	}
	delete _inventory[idx];
}
void Character::unequip(int idx) {
	if(idx >= 0 && idx < 4 && _inventory[idx]) {
		if(_groundCount < 10) {
			_ground[_groundCount++] = _inventory[idx];
			_inventory[idx] = NULL;
		}
		else {
			handle_groundFull(idx);
		}
		std::cout << "Unequip materia at idx: " << idx << std::endl;
	}
}

void Character::use(int idx, ICharacter& target) {
	if(idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Fail to use materia" << std::endl;
}

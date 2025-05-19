/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:42 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/19 11:34:15 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_name = "No name RANDOM";
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) {
	_name = name;
	_HitPoints = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << "Constructor with name" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& obj) {
	*this = obj;
}

ClapTrap& ClapTrap::operator=(ClapTrap& obj) {
	_name = obj._name;
	_HitPoints = obj._HitPoints;
	_EnergyPoints = obj._EnergyPoints;
	_AttackDamage = obj._AttackDamage;
	std::cout << "Copy assignment operator" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	
	if (_EnergyPoints <= 0 || _HitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy / life points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
	_EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	
	if(amount > _HitPoints) {
		_HitPoints = 0;
	}
	else {
		_HitPoints -= amount;
	}
	if (_HitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " DIE!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining Hit Points: " << _HitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	
	if (_EnergyPoints <= 0 || _HitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " has no energy / life points left!" << std::endl;
		return;
	}
	
	_HitPoints += amount;
	_EnergyPoints--;
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " points! Remaining Hit Points: " << _HitPoints << std::endl;
}
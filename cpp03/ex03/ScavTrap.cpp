/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:12:58 by pn                #+#    #+#             */
/*   Updated: 2025/05/19 07:33:19 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "No name RANDOM";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "Scav default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "Scav constructor with name" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
	std::cout << "Scav copy constructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	
    ClapTrap::operator=(obj);
	std::cout << "Scav copy assignment operator" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scav Destructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)  {
	
	if (_EnergyPoints <= 0 || _HitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no energy / life points left!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
	_EnergyPoints--;
}

void ScavTrap::guardGate() {
	if (_HitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no life points left!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
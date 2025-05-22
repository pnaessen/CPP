/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:32:54 by pn                #+#    #+#             */
/*   Updated: 2025/05/21 21:54:43 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
	_name = "No name RANDOM";
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
	std::cout << "Diamond default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	_name = name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
	std::cout << "Diamond constructor with name" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj) {
	std::cout << "Diamond copy constructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	ClapTrap::operator=(obj);
	std::cout << "Diamond copy assignment operator" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Diamond Destructor" << std::endl;
}

void DiamondTrap::whoAmI() {

	std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	
	ScavTrap::attack(target);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:18:19 by pn                #+#    #+#             */
/*   Updated: 2025/05/18 18:29:16 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap constructor with name called" << std::endl;
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)  {
	
	ClapTrap::operator=(obj);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (_EnergyPoints <= 0 || _HitPoints <= 0) {
		std::cout << "FragTrap " << _name << " has no energy / life points left!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _AttackDamage << " points of damage!" << std::endl;
	_EnergyPoints--;
}

void FragTrap::highFivesGuys() {
	
	if (_HitPoints <= 0) {
		std::cout << "FragTrap " << _name << " has no life points left!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " requests  a high five! #positive " << std::endl;
}

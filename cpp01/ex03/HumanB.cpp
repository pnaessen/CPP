/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:48:00 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/09 09:47:25 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) {
	_name = name;
	_weapon = NULL;
}

void HumanB::setWeapon(Weapon& Weapon) {
	_weapon = &Weapon;
}

void HumanB::attack() const { 
	if(_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << "Weapon not set ..." << std::endl;
}

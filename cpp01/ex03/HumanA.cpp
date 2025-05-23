/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:55:01 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/09 09:47:19 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : _weapon(weapon) {
	_name = name;
}

void HumanA::attack() const { 
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
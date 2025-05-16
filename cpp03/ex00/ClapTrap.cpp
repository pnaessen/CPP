/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:42 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/16 15:33:14 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	_HitPoint = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
	std::cout << "Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string& name) {
	_name = name;
	_HitPoint = 10;
	_EnergyPoints = 10;
	_AttackDamage = 0;
}


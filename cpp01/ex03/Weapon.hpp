/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 09:22:58 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/07 13:42:20 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon {
private:
	std::string _type;

public:
	Weapon(const std::string& type);
	
	std::string getType() const;
	void setType(const std::string& newType);
};

#endif
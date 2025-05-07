/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:23:39 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/07 13:56:10 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class Weapon;

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(const std::string& name);
	
		void setWeapon(Weapon& weapon);
		void attack() const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:19:21 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/07 13:56:25 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"
class Weapon;

class HumanA {
	private:
		std::string _name;
		Weapon& _weapon;

	public:
		HumanA(const std::string& name, Weapon& weapon);
	
		void attack() const;
};

#endif
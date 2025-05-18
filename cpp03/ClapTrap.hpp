/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:14:05 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/18 14:35:00 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
	#define CLAPTRAP_HPP
	
	#include <string>
	#include <iostream>
	
	class ClapTrap {
		
		protected:
			std::string _name;
			unsigned int _HitPoints;
			unsigned int _EnergyPoints;
			unsigned int _AttackDamage;
		
		public:
			ClapTrap();
			ClapTrap(const std::string& name);
			ClapTrap(const ClapTrap& obj);
			~ClapTrap();
			
			ClapTrap& operator=(const ClapTrap& obj);

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
	};

#endif
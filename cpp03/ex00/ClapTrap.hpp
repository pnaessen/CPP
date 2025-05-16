/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:14:05 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/16 15:33:34 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
	#define CLAPTRAP_HPP
	
	#include <string>
	#include <str
	
	class ClapTrap {
		
		private:
			std::string _name;
			unsigned int _HitPoint;
			unsigned int _EnergyPoints;
			unsigned int _AttackDamage;
		
		public:
			ClapTrap();
			ClapTrap(std::string& name);
			ClapTrap(ClapTrap& obj);
			~ClapTrap();
			
			ClapTrap& operator=(ClapTrap& obj);

			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
	};

#endif
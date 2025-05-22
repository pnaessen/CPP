/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:27:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 23:08:47 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

	#include "ICharacter.hpp"
	
	class Character : public ICharacter {
		private:
			std::string _name;
			AMateria* _inventory[4];
			
		public:
			Character();
			Character(const std::string& name);
			Character(const Character& obj);
			~Character();

			Character& operator=(const Character& obj);
			std::string  const & getName();
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);
	};

#endif
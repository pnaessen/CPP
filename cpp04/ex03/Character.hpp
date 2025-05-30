/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:27:03 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/30 15:35:11 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

	#include "ICharacter.hpp"
	
	class Character : public ICharacter {
		private:
			std::string _name;
			AMateria* _inventory[4];
			AMateria* _ground[10];
			int _groundCount;
			
		public:
			Character();
			Character(const std::string& name);
			Character(const Character& obj);
			virtual ~Character();

			Character& operator=(const Character& obj);
			std::string  const & getName() const ;
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);
	};

#endif
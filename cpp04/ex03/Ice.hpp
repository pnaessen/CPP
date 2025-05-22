/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:55:15 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 15:57:23 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

	#include "AMateria.hpp"

	class Ice : public AMateria {
		private: 

		public:
			Ice();
			Ice(std::string name);
			Ice(const Ice& obj);
			~Ice();

			Ice& operator=(const Ice& obj);
			
			void use(ICharacter& target);
			AMateria* clone() const;
	};

#endif 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 06:59:38 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 09:41:20 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

	#include <string>
	#include <iostream>
	#include "ICharacter.hpp"

	class AMateria {
		protected:
			std::string _type;
		
		public:
			AMateria();
			AMateria(std::string const& type);
			AMateria(const AMateria& obj);
			virtual ~AMateria();
			AMateria& operator=(const AMateria& obj);
		
			std::string const & getType() const;
			virtual AMateria* clone() const = 0;
			virtual void use(ICharacter& target);
	};

#endif
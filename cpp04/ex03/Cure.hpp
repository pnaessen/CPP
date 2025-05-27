/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:19:33 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/27 09:15:23 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

	#include "AMateria.hpp"

	class Cure : public AMateria {
		private: 

		public:
			Cure();
			Cure(std::string name);
			Cure(const Cure& obj);
			~Cure();

			Cure& operator=(const Cure& obj);
			
			void use(ICharacter& target);
			AMateria* clone() const;
	};

#endif 
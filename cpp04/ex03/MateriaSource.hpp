/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:58:32 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 16:04:05 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

	#include "IMateriaSource.hpp"

	class MateriaSource : public IMateriaSource {
			private:

			public:
				MateriaSource();
				MateriaSource(const MateriaSource& obj);
				~MateriaSource();

				MateriaSource& operator=(MateriaSource& obj);
				void learnMateria(AMateria*);
				AMateria* createMateria(std::string const& type);
	};
	
#endif
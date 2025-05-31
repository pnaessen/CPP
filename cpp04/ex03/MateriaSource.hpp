/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:58:32 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/31 23:37:45 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

	#include "IMateriaSource.hpp"
	#include "AMateria.hpp"

	class MateriaSource : public IMateriaSource {
			private:
				AMateria* _materia[4];
			public:
				MateriaSource();
				MateriaSource(const MateriaSource& obj);
				virtual ~MateriaSource();

				MateriaSource& operator=(const MateriaSource& obj);
				void learnMateria(AMateria*);
				AMateria* createMateria(std::string const& type);
	};
	
#endif
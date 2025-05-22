/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:58:32 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 18:03:53 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

	#include "IMateriaSource.hpp"

	class MateriaSource : public IMateriaSource {
			private:
				AMateria* _materia[4];
				int _count;
			public:
				MateriaSource();
				MateriaSource(const MateriaSource& obj);
				~MateriaSource();

				MateriaSource& operator=(const MateriaSource& obj);
				void learnMateria(AMateria*);
				AMateria* createMateria(std::string const& type);
	};
	
#endif
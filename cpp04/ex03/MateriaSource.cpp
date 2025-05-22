/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:04:19 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/22 18:03:22 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()  {
		std::cout << " MateriaSource constructor call" << std::endl;	
}

MateriaSource::MateriaSource(const MateriaSource& obj)  {
	std::cout << " MateriaSource copy constructor call" << std::endl;	

}

MateriaSource::~MateriaSource() {
	std::cout << " MateriaSource destructor call" << std::endl;	

}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	if(this != &obj) {
		
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria*) {
	
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	
}
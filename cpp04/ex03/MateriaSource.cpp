/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:04:19 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/05 09:19:49 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()  {
		std::cout << " MateriaSource constructor call" << std::endl;
		for(int i = 0; i < 4; i++) {
			_materia[i] = NULL;
		}
}

MateriaSource::MateriaSource(const MateriaSource& obj)  {
	std::cout << " MateriaSource copy constructor call" << std::endl;
	
	for(int i = 0; i < 4; i++) {
		_materia[i] = NULL;
	}

	for(int i = 0; i < 4; i++) {
		if(obj._materia[i] != NULL) {
			_materia[i] = obj._materia[i]->clone();
		}
	}
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++) {
		if(_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
	}
	}
	std::cout << "MateriaSource destructor call" << std::endl;

}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	
	std::cout << "MateriaSource operator call" << std::endl;
	if(this != &obj) {
		for (int i = 0; i < 4; i++) {
			delete _materia[i];
			_materia[i] = NULL;
		}
	
		for(int i = 0; i < 4; i++) {
			if(obj._materia[i] != NULL) {
				_materia[i] = obj._materia[i]->clone();
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if(!m)
		return;
	for(int i = 0; i< 4; i++) {
		if(_materia[i] == m) {
			std::cout << "Materia already learned" << std::endl;
			return ;
		}
	}
	
	for(int i = 0; i < 4; i++) {
		if(!_materia[i]) {
			_materia[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {

	for (int i = 0; i < 4; i++) {
		if (_materia[i] != NULL && _materia[i]->getType() == type) {
			return _materia[i]->clone();
		}
	}
	return NULL;
}
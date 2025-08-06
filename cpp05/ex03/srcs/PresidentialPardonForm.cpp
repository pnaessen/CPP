/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:13:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/23 11:11:10 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Form", 25, 5), _target(target) {
	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target) {
	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {

	if(this != &obj) {
		AForm::operator=(obj);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	
}


void PresidentialPardonForm::executeForm() const {

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
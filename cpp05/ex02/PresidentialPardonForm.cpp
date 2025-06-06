/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:13:34 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/06 16:17:22 by pnaessen         ###   ########lyon.fr   */
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

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {

	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw std::out_of_range("Form grade is to Hight");

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
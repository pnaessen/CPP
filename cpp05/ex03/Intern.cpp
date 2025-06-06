/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:49:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/06 18:00:16 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	
}

Intern::~Intern() {
	
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	
	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0: return new ShrubberyCreationForm(target);
				case 1: return new RobotomyRequestForm(target);
				case 2: return new PresidentialPardonForm(target);
			}
		}
	}
	
	std::cout << "Intern cannot create " << formName << " form" << std::endl;
	throw FormNotFoundException();
}

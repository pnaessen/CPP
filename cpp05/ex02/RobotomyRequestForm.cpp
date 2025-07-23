/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:38:40 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/23 09:57:07 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Form", 72, 45), _target(target) {
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target) {
	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	
	if(this != &obj) {
		AForm::operator=(obj);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	
}

void RobotomyRequestForm::executeForm() const {
	
		
	std::cout << "Makes some drilling noises." << std::endl;
	
	//srand(time(0));
	if(rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully " << std::endl;
	}
	else 
		std::cout << "The robotomy of " << _target << " failed" << std::endl;

}
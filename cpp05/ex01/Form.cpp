/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:37:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/05 16:11:25 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(const std::string &name, int signGrade, int executeGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighE();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowE();
	if (name.empty())
		throw std::invalid_argument("Form name cannot be empty");
	_isSigned = false;
}

Form::Form(const Form &obj) : _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {
}

Form &Form::operator=(const Form &obj) {
	if (this != &obj) {
		_isSigned = obj._isSigned;
	}
	return *this;
}

Form::~Form() {
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowE();
	_isSigned = true;
}



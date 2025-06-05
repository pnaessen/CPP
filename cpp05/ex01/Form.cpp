/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:37:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/05 17:35:01 by pnaessen         ###   ########lyon.fr   */
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


const std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

std::ostream& operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() 
	   << " (signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecuteGrade() << ")";
	return os;
}
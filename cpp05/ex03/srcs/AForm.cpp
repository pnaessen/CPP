/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:37:46 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/18 08:30:30 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm(const std::string &name, int signGrade, int executeGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw GradeTooLowException();
	if (name.empty())
		throw std::invalid_argument("Form name cannot be empty");
	_isSigned = false;
}

AForm::AForm(const AForm &obj) : _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _executeGrade(obj._executeGrade) {
}

AForm &AForm::operator=(const AForm &obj) {
	if (this != &obj) {
		_isSigned = obj._isSigned;
	}
	return *this;
}

AForm::~AForm() {
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade)
		throw std::out_of_range("Form grade is to Hight");
	_isSigned = true;
}


void AForm::execute(const Bureaucrat &executor) const {
	
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw std::out_of_range("Form grade is to Hight");
	
	executeForm();
	
}

const std::string AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

std::ostream& operator<<(std::ostream &os, const AForm &form) {
	os << "Form " << form.getName() 
	   << " (signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", sign grade: " << form.getSignGrade()
	   << ", exec grade: " << form.getExecuteGrade() << ")";
	return os;
}

const char* AForm::GradeTooHighException::what() const throw () {
	return "Form grade too hight";
}

const char* AForm::GradeTooLowException::what() const throw () {
	return "Form grade too low";
}

const char* AForm::FormNotSignedException::what() const throw () {
	return "Form not sign";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:35 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/31 09:01:07 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	if (name.empty())
		throw std::invalid_argument("Bureaucrat name cannot be empty");
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj._name), _grade(obj._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
	if (this != &obj) {
		_grade = obj._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if(_grade == 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if(_grade == 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) {
	
	try {
		form.execute(*this);
		std::cout << _name << " execute " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << _name << " couldn't execute " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}


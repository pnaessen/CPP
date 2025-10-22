/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:01:35 by pnaessen          #+#    #+#             */
/*   Updated: 2025/09/24 09:58:14 by pnaessen         ###   ########lyon.fr   */
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

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw () {
	return "Grade is too hight";
}

const char* Bureaucrat::GradeTooLowException::what() const throw () {
	return "Grade is too low";
}
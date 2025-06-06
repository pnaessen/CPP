/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:55:13 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/06 11:18:30 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Form", 145, 137), _target(target) {
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj), _target(obj._target) {
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	
	if (this != &obj) {
		AForm::operator=(obj);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
	
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	
	std::string outFileName = _target + "_shrubbery";
	std::ofstream outFile(outFileName.c_str());
	if(outFile.is_open()) {
		outFile << "    /\    /\        /\     /\      /\       /\      /\ ";
  		outFile << "   /  \  /  \      /  \   /  \    /  \     /  \    /  \ ";
 		outFile << "  /____\/____\    /____\ /____\  /____\   /____\  /____\ ";
     	outFile << "	||    ||        ||     ||      ||       ||      || ";
     	outFile << "	||    ||        ||     ||      ||       ||      ||	";
	}
	else
		throw std::runtime_error("Error can't creat the Form");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:55:13 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/23 09:32:43 by pnaessen         ###   ########lyon.fr   */
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

void ShrubberyCreationForm::executeForm() const {
	
	// if (!getIsSigned())
	// 	throw FormNotSignedException();
	// if (executor.getGrade() > getExecuteGrade())
	// 	throw std::out_of_range("Form grade is to Hight");
	
	std::string outFileName = _target + "_shrubbery";
	std::ofstream outFile(outFileName.c_str());
	if(outFile.is_open()) {
		outFile << "       /\\      " << std::endl;
		outFile << "      /  \\     " << std::endl;
		outFile << "     /____\\    " << std::endl;
		outFile << "        ||     " << std::endl;
		outFile << "        ||     " << std::endl;
		outFile << std::endl;
		outFile << "    /\\    /\\   " << std::endl;
		outFile << "   /  \\  /  \\  " << std::endl;
		outFile << "  /____\\/____\\ " << std::endl;
		outFile << "      ||       " << std::endl;
		outFile << "      ||       " << std::endl;
		outFile << std::endl;
		outFile << "  /\\  /\\  /\\  " << std::endl;
		outFile << " /  \\/  \\/  \\ " << std::endl;
		outFile << "/____________\\" << std::endl;
		outFile << "      ||       " << std::endl;
		outFile << "      ||       " << std::endl;
		outFile.close();
	}
	else
		throw std::runtime_error("Error can't create the file");
}

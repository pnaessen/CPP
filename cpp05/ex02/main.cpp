/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:29:05 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/31 09:01:18 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void printSeparator(const std::string& testName) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "TEST: " << testName << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void testPresidentialPardonForm() {
	
	printSeparator("Presidential Pardon Form");
	
	try {
		PresidentialPardonForm form("first");
		Bureaucrat riko("riko", 1);
		riko.signForm(form);
		riko.executeForm(form);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
}

void testRobotomy() {

	printSeparator("Test Robotomy");
	
	try {
		RobotomyRequestForm form("first");
		Bureaucrat riko("riko", 1);
		riko.signForm(form);
		riko.executeForm(form);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

}


void testCatchTooHight() {
	
	printSeparator("Catch Too High Exception");
	
	try {
		Bureaucrat riko("riko", 1);
		riko.incrementGrade();
		Bureaucrat alice("alice", 0);
	} 
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testCatchTooLow() {
	
	printSeparator("Catch Too Low Exception");
	
	try {
		Bureaucrat riko("Riko", 150);
		riko.decrementGrade();
		Bureaucrat alice("alice", 151);
	} 
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

}

void basicTest() {
	
	printSeparator("Basic Test");
	
	try {
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After incrementing, Grade: " << bob.getGrade() << std::endl;
		bob.decrementGrade();
		std::cout << "After decrementing, Grade: " << bob.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testFormShrubbery() {
	
	printSeparator("Form Shrubbery");
	
	try {
			ShrubberyCreationForm form("first");
			Bureaucrat riko("riko", 10);
			riko.signForm(form);
			riko.executeForm(form);
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main () {
	

	std::string input;
	while (1)
	{
		if (!std::cin.eof())
		{
			std::cout << std::endl << BOLD_RED << "PLEASE CHOOSE BETWEEN THESE TEST :" << std::endl
				<< "	1 - Basic test" << std::endl
				<< "	2 - Test Catch Too Hight" << std::endl
				<< "	3 - Test Catch Too Low" << std::endl
				<< "	4 - Test Form Shrubbery" << std::endl
				<< "	5 - Test Form Robotomy" << std::endl
				<< "	6 - Test Presidential Pardon Form" << std::endl
				<< "	X - exit" << RESET << std::endl << std::endl;
		}
		if (!(std::cin >> input))
		{
			std::cout << "Error, exit program" << std::endl;
			return (1);
		}
		if (input == "1")
			basicTest();
		else if (input == "2")
			testCatchTooHight();
		else if (input == "3")
			testCatchTooLow();
		else if (input == "4")
			testFormShrubbery();
		else if (input == "5")
			testRobotomy();
		else if (input == "6")
			testPresidentialPardonForm();
		else if (input == "X" || input == "x")
			return (0);
		else
			std::cout << "Please choose a valid test" << std::endl;
	}
		return 0;
}



// std::exception
// ├── std::bad_alloc          // Échec d'allocation mémoire
// ├── std::bad_cast           // Cast invalide
// ├── std::bad_typeid         // typeid sur pointeur null
// ├── std::logic_error
// │   ├── std::invalid_argument
// │   ├── std::domain_error
// │   ├── std::length_error
// │   └── std::out_of_range
// └── std::runtime_error
//     ├── std::range_error
//     ├── std::overflow_error
//     └── std::underflow_error

	
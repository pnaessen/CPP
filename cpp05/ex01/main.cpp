/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:29:05 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/05 17:42:09 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


void printSeparator(const std::string& testName) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "TEST: " << testName << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void testCatchTooHight() {
	
	printSeparator("Catch Too High Exception");
	
	try {
		Bureaucrat riko("riko", 1);
		riko.incrementGrade();
		Bureaucrat alice("alice", 0);
	} 
	catch (const Bureaucrat::GradeTooHighE &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowE &e) {
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
	catch (const Bureaucrat::GradeTooHighE &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowE &e) {
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
		std::cout << "Bureaucrat: " << bob.getName() << ", Grade: " << bob.getGrade() << std::endl;
		bob.incrementGrade();
		std::cout << "After incrementing, Grade: " << bob.getGrade() << std::endl;
		bob.decrementGrade();
		std::cout << "After decrementing, Grade: " << bob.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighE &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowE &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testFormCreationAndSigning() {
	printSeparator("Form Creation and Signing Test");
	
	try {
		Form taxForm("Tax Return", 50, 25);
		Bureaucrat alice("Alice", 30);
		Bureaucrat bob("Bob", 75);
		
		std::cout << taxForm << std::endl;
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		
		alice.signForm(taxForm); 
		bob.signForm(taxForm); 
		
		Form secretForm("Secret", 1, 1);
		bob.signForm(secretForm);
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
				<< "	4 - Test Form Creation And Signing" << std::endl
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
			testFormCreationAndSigning();
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

	
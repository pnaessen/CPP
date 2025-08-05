/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:29:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/05 17:36:57 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RESET       "\033[0m"
#define RED         "\033[31m"
#define BOLD_RED    "\033[1;31m"


	#include <iostream>
	#include <string>
	#include <exception>
	#include "AForm.hpp"
	class AForm;
	
	class Bureaucrat {
		private:
			const std::string _name;
			int _grade;
			Bureaucrat();
		public:
			Bureaucrat(const std::string &name, int grade);
			Bureaucrat(const Bureaucrat &obj);
			Bureaucrat &operator=(const Bureaucrat &obj);
			~Bureaucrat();

			const std::string &getName() const;
			int getGrade() const;
			void incrementGrade();
			void decrementGrade();
			void signForm(AForm &form);
			void executeForm(const AForm& form);

			class GradeTooHighException : public std::exception {
				public:
					const char *what() const throw() {
						return "Grade too high";
					}
			};

			class GradeTooLowException : public std::exception {
				public:
					const char *what() const throw() {
						return "Grade too low";
					}
			};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
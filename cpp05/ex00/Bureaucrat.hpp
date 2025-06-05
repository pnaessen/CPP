/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:29:29 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/05 15:58:25 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// Reset
#define RESET       "\033[0m"

// Regular colors
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

// Bold colors
#define BOLD_BLACK  "\033[1;30m"
#define BOLD_RED    "\033[1;31m"
#define BOLD_GREEN  "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE   "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN   "\033[1;36m"
#define BOLD_WHITE  "\033[1;37m"

// Background colors
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_WHITE    "\033[47m"


	#include <iostream>
	#include <string>

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

			class GradeTooHighE : public std::exception {
				public:
					const char *what() const throw() {
						return "Grade too high";
					}
			};

			class GradeTooLowE : public std::exception {
				public:
					const char *what() const throw() {
						return "Grade too low";
					}
			};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Fixed);


#endif